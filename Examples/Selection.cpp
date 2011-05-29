#include "GeneticSoup.hpp"
#include "StrGenome.hpp"
#if _WIN32
#   define _CRTDBG_MAP_ALLOC
#   include <crtdbg.h>
#endif

using namespace GeneticSoup;


int main(int argc, char** argv)
{
    time_t seconds;
    time(&seconds);

    srand((unsigned int) seconds);
    rand();

    // Notice the pointer!
    Population<StrGenome*> population(20, "initial");

    for (unsigned int i=0; i<population.Size(); i++) {
        StrGenome* g =  new StrGenome();
        g->Create();
        g->Evaluate();

        population.Push(g);
    }
    
    StrGenome* selected = Selection<StrGenome*>::RouletteWheel(population);
    std::cout << selected << std::endl;
    
#if _WIN32
    _CrtDumpMemoryLeaks();
#endif
    
    delete Helpers::Random::Instance();

    return 0;
}
