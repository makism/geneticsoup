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
    : Genome<char>(11)
    {
    }
    
    void Generate(void)
    {
        char temp;
        for (unsigned int i = 0; i<mSize; i++) {
           temp = (char)((rand() % 25) + 65);
           
           this->Push(temp);
        }
    }
    
    float EvaluateCallback(void)
    {
        const std::string final = "Hello World";
        float result = 0.0f;
        
        for (unsigned int i=0; i<mSize; i++) {
            int diff = 0;
            char c = this->At(i);
            char t = final[i];
            
            result += float(abs((int(t) - int(c))));
        }
        
        return result;
    }
};


int main(int argc, char** argv)
{
    time_t seconds;
    time(&seconds);

    srand((unsigned int) seconds);
    rand();
    
#if _WIN32
    _CrtDumpMemoryLeaks();
#endif

    delete Helpers::Random::Instance();

    return 0;
}
