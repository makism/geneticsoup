#include "GeneticSoup.hpp"
#include "BinaryNumberGenome.hpp"

using namespace GeneticSoup;




int main(int argc, char** argv)
{
    time_t seconds;
    time(&seconds);

    srand((unsigned int) seconds);
    rand();
    
    BinaryNumberGenome bg;
    
    std::cout << "Original: " << bg << std::endl;
 
//     Mutation<BinaryNumberGenome>::_Exchange2(bg);
    bg.Mutate();
    bg.Evaluate();
    
    if (bg.IsMutated())
        std::cout << " Mutated: " << bg << std::endl;
    
    delete Helpers::Random::Instance();
    return 0;
}
