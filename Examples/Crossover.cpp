#include "GeneticSoup.hpp"
#include "BinaryNumberGenome.hpp"

using namespace GeneticSoup;


int main(int argc, char** argv)
{
    time_t seconds;
    time(&seconds);

    srand((unsigned int) seconds);
    rand();
    
    BinaryNumberGenome father;
    BinaryNumberGenome mother;
    BinaryNumberGenome child1;
    BinaryNumberGenome child2;
    
    std::cout << father << std::endl;
    std::cout << mother << std::endl;
    
    std::cout << std::endl;
    
    Crossover<BinaryNumberGenome>::TwoPointExchange(father, mother, child1, child2);
    
    std::cout << std::endl;
    std::cout << child1 << std::endl;
    std::cout << child2 << std::endl;
    
    delete Helpers::Random::Instance();
    
    return 0;
}
