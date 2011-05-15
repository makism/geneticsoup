#include "GeneticSoup.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
// #define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
// #include <crtdbg.h>

using namespace GeneticSoup;

class StrGenome: public Genome<std::string>
{
public:
    StrGenome(void)
        : Genome<std::string>(5) {

    }

    virtual ~StrGenome(void) {

    }

    void Generate(void) {
        for (unsigned int i = 0; i < mSize; i++) {
            std::ostringstream oss;

            for (unsigned int x = 0; x < mSize; x++) {
                char ch = (char)((rand() % 25) + 65);
                oss << ch;
            }
            
            std::string temp = oss.str();

			this->Push(temp);
        }

    }

    float EvaluateCallback(void) {
        int hits = 0;
        char curr;

        for (unsigned int i = 0; i < mSize; i++) {
            std::string str = this->At(i);

            for (unsigned int x = 0; x < mSize; x++) {
                curr = str.at(x);

                if (curr == 'A') {
                    hits++;
                }
            }
        }

        return float(hits) / float(mSize * mSize);
    }
};

int main(int argc, char** argv)
{
    time_t seconds;
    time(&seconds);

    srand((unsigned int) seconds);
    rand();

    Population<StrGenome*> *population = new Population<StrGenome*>(10);

    StrGenome* g = new StrGenome();
    g->Create();
    g->Evaluate();

    population->Push(g);

    StrGenome* g2 = population->At(0);
    std::cout << g2->ToString(true) << std::endl;

    delete population;

    //_CrtDumpMemoryLeaks();
    return 0;
}
