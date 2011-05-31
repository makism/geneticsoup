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
        StrGenome* g = new StrGenome();
        g->Create();
        g->Evaluate();

        population.Push(g);
    }

    while (population.Next())
        std::cout << population.Current() << std::endl;
    
//     std::cout << std::endl
//               << "Average Fitness: " << population.AverageFitness() << std::endl
//               << "   Best Fitness: " << population.BestFitness()    << std::endl
//               << "  Worst Fitness: " << population.WorstFitness()   << std::endl;
//               
//     std::cout << " Best genome: " << population.BestGenome() << std::endl
//               << "Worst genome: " << population.WorstGenome() << std::endl;

#if _WIN32
    _CrtDumpMemoryLeaks();
#endif

    return 0;
}
