#include "GeneticSoup.hpp"
#include "StrGenome.hpp"
#if _WIN32
#   define _CRTDBG_MAP_ALLOC
#   include <crtdbg.h>
#endif

using namespace GeneticSoup;


// class MyIsland: public Island<StrGenome*>
// {
// public:
//     MyIsland(void)
//         : Island<StrGenome*>(2, 5, 10) {
// 
//     }
// 
//     ~MyIsland(void) {
// 
//     }
// 
//     void Initialize(void) {
// //         for (unsigned int i = 0; i < mPopulationSize; i++) {
// //             StrGenome* genome = new StrGenome();
// //             genome->Create();
// //             genome->Evaluate();
// // 
// //             mCurrentPopulation->Push(genome);
// //         }
//     }
// 
//     void AdvanceEpoch(void) {
//         Island<StrGenome*>::AdvanceEpoch();
//     }
// 
// };

int main(int argc, char** argv)
{
    time_t seconds;
    time(&seconds);

    srand((unsigned int) seconds);
    rand();
	
// 	MyIsland island;
// 	island.Initialize();
// 	island.AdvanceEpoch();

//     MyIsland* island = new MyIsland();
//     island->Initialize();
//     island->AdvanceEpoch();
// 
//     while(island->CurrentPopulation()->Next())
//     {
//         StrGenome* curr = island->CurrentPopulation()->Current();
//         std::cout << curr->ToString(true) << std::endl;
//     }

//     delete island;

#if _WIN32
    _CrtDumpMemoryLeaks();
#endif

    return 0;
}
