#define GENETICSOUP_NO_ID_COUNTER
#include "GeneticSoup.hpp"
#if _WIN32
#   define _CRTDBG_MAP_ALLOC
#   include <crtdbg.h>
#endif

using namespace GeneticSoup;

class CharGenome: public Genome<char>
{

public:
    CharGenome(void)
            : Genome<char>(12, Function::Cost) {

    }

    void Generate(void) {
        char temp;
        for (unsigned int i = 0; i<mSize; i++) {
            temp = (char)((rand() % 90) + 32);

            this->Push(temp);
        }
    }

    float EvaluateCallback(void) {
        const std::string final = "Hello world!";
        float result = 0.0f;

        for (unsigned int i=0; i<mSize; i++) {
            int diff = 0;
            char c = this->At(i);
            char t = final[i];

            result += float(abs((int(t) - int(c))));
        }
        
        return result;
    }
    
    void Mutate(void) {
        if (Mutation< Genome<char> >::SuccessCheck())
            return;
        
        mIsMutated = true;
        
        int offset = Helpers::Random::Instance()->Generate(0, mSize - 1);
        int delta = (rand() % 90) + 32;
     
        this->At(offset) = (char)((mPool->at(offset) + delta) % 122);
    }
};

class MyIsland: public Island<CharGenome*>
{
public:
    MyIsland(void)
            : Island<CharGenome*>(1024, 2048, 12) {
        SetEliteCopies(256);
    }

    ~MyIsland(void) {

    }

    void Initialize(void) {
        mCurrentPopulation->AutoPopulate();
    }

    void AdvanceEpoch(void) {
        Island<CharGenome*>::AutoAdvanceEpoch();
    }

};


int main(int argc, char** argv)
{
    time_t seconds;
    time(&seconds);

    srand((unsigned int) seconds);
    rand();

    MyIsland island;
    island.Initialize();
    island.Go();

    std::cout << "Completed..." << std::endl;
    std::cout << island.CurrentPopulation()->BestGenome() << std::endl;

#if _WIN32
    _CrtDumpMemoryLeaks();
#endif

    delete Helpers::Random::Instance();

    return 0;
}
