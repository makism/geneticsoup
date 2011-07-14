#include "GeneticSoup.hpp"
#include "StrGenome.hpp"
#if _WIN32
#   define _CRTDBG_MAP_ALLOC
#   include <crtdbg.h>
#endif

using namespace GeneticSoup;


class MyIsland: public Island<StrGenome*>
{
public:
    MyIsland(void)
            : Island<StrGenome*>(128, 32, 10) {

    }

    ~MyIsland(void) {

    }

    void Initialize(void) {
        mCurrentPopulation->AutoPopulate();
    }

    void AdvanceEpoch(void) {
        Island<StrGenome*>::AutoAdvanceEpoch();
    }

};

int main(int argc, char** argv)
{
    time_t seconds;
    time(&seconds);

    srand((unsigned int)seconds);
    rand();
    
    MyIsland island;
    island.Initialize();
    island.AdvanceEpoch();

    
#if _WIN32
    _CrtDumpMemoryLeaks();
#endif

    delete Helpers::Random::Instance();
    
    return 0;
}
