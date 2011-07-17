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
    Population<StrGenome*> nextPopulation(20, "2nd gen");

    population.AutoPopulate();

    Selection<StrGenome*>::Elitism(population, nextPopulation, 2);
    StrGenome* selected = Selection<StrGenome*>::RouletteWheel(population);
    
    std::cout << "Current Population" << std::endl;
    while (population.Next())
        std::cout << population.Current() << std::endl;

    std::cout << std::endl
              << "Selected: " << selected
              << std::endl;
    
    std::cout << std::endl << "Next Population" << std::endl;
    nextPopulation.AutoPopulate();
    
    while (nextPopulation.Next())
        std::cout << nextPopulation.Current() << std::endl;


#if _WIN32
    _CrtDumpMemoryLeaks();
#endif

    delete Helpers::Random::Instance();

    return 0;
}
