#include "GeneticSoup.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <cstdlib>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace GeneticSoup;


class StrGenome: public Genome<std::string>
{
public:
    StrGenome(void)
        : Genome(5) {

    }

    void Generate(void) {
        for (unsigned int i = 0; i < mSize; i++) {
            std::ostringstream oss;

            for (unsigned int x = 0; x < mSize; x++) {
                char ch = (char)((rand() % 25) + 65);
                oss << ch;
            }

            Push(oss.str());
        }

    }

    float EvaluateCallback(void) {
        int hits = 0;
        char curr;

        for (unsigned int i = 0; i < mSize; i++) {
            std::string str = At(i);

            for (unsigned int x = 0; x < mSize; x++) {
                curr = str.at(x);

                if (curr == 'A') {
                    hits++;
                }
            }
        }

        return static_cast<float>(static_cast<float>(hits) / (mSize * mSize));
    }
};

class MyIsland: public Island<StrGenome*>
{
public:
    MyIsland(void)
        : Island(2, 5, 10) {

    }

    ~MyIsland(void) {

    }

    void Initialize(void) {
        for (unsigned int i = 0; i < mPopulationSize; i++) {
            StrGenome* genome = new StrGenome();
            genome->Create();
            genome->Evaluate();

            mCurrentPopulation->Push(genome);
        }
    }

    void AdvanceEpoch(void) {
        Island<StrGenome*>::AdvanceEpoch();
    }

};




int main(int argc, char** argv)
{
    time_t seconds;
    time(&seconds);

    srand((unsigned int) seconds);
    rand();

    MyIsland* island = new MyIsland();
    island->Initialize();
    island->AdvanceEpoch();

    while(island->CurrentPopulation()->Next())
    {
        StrGenome* curr = island->CurrentPopulation()->Current();
        std::cout << curr->ToString(true) << std::endl;
    }

    delete island;

    //_CrtDumpMemoryLeaks();
    return 0;
}
