#include "GeneticSoup.hpp"
#include "StrGenome.hpp"

using namespace GeneticSoup;


int main(int argc, char** argv)
{
    time_t seconds;
    time(&seconds);

    srand((unsigned int) seconds);
    rand();
 
    
    StrGenome strGenome1;
    strGenome1.Create();
    strGenome1.Evaluate();
    
    std::cout << strGenome1 << std::endl;
    
    Mutation<StrGenome>::Exchange2(strGenome1);
    
    std::cout << strGenome1 << std::endl;
    
    delete Helpers::Random::Instance();
    return 0;
}
