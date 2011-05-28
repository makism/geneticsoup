#include "GeneticSoup.hpp"
#include "BinaryNumberGenome.hpp"

using namespace GeneticSoup;




int main(int argc, char** argv)
{
    time_t seconds;
    time(&seconds);

    srand((unsigned int) seconds);
    rand();
    
//     MyBinaryGenome bg;
//     bg.Create();
//     
//     bg.Mutate();
//     
//     std::cout << bg << std::endl;
//  
    delete Helpers::Random::Instance();
    return 0;
}
