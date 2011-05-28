#include "GeneticSoup.hpp"
#include "StrGenome.hpp"

using namespace GeneticSoup;


int main(int argc, char** argv)
{
    time_t seconds;
    time(&seconds);

    srand((unsigned int) seconds);
    rand();
    
    StrGenome strg;
    strg.Create();
    strg.Evaluate();
    
    std::cout << strg.ToString(true) << std::endl;
    
    // Copy-ctor.
    StrGenome strg2(strg);
    
    std::cout << strg2.ToString(true) << std::endl;

    return 0;
}
