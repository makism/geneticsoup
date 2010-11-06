#include "GeneticSoup.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


class StrGenome: public GeneticSoup::Genome<std::string>
{
public:
    StrGenome(void)
        : Genome(5) {

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

        return float(hits) / float(mSize * mSize);
    }
};

int main(int argc, char** argv)
{
    time_t seconds;
    time(&seconds);

    srand((unsigned int) seconds);
    rand();

    GeneticSoup::Population<StrGenome> *population = new GeneticSoup::Population<StrGenome>(10);

    StrGenome* g = new StrGenome();
    g->Create();
    g->Evaluate();

    population->Push(*g);

    StrGenome g2 = population->At(0);
    std::cout << g2.ToString(true) << std::endl;

    delete population;

    //_CrtDumpMemoryLeaks();
    return 0;
}
