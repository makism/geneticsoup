#include "GeneticSoup.hpp"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


int main(int argc, char** argv)
{

    std::cout << "Genetic Soup Version: " << GENETICSOUP_VERSION_STRING << std::endl;

    GeneticSoup::Pool<int> *p = new GeneticSoup::Pool<int>(10);
    GeneticSoup::Pool<double> p2(100);
    GeneticSoup::Pool<unsigned long long int> p3;

    int temp = 10;
    p->Push(temp);

    double temp2 = 34.034523663;
    p2.Push(temp2);

    unsigned long long int temp3 = std::numeric_limits<unsigned long long int>::max();
    p3.Push(temp3);


    std::cout << p->HasFixedSize() << "\t" << p->Size() << std::endl;
    std::cout << p2.HasFixedSize() << "\t" << p2.Size() << std::endl;
    std::cout << p3.HasFixedSize() << "\t" << p3.Size() << std::endl;


    std::cout << "p->At(0): " << p->At(0) << std::endl;
    std::cout << "p2[0]: " << p2[0] << std::endl;
    std::cout << "p3[0]: " << p3[0] << std::endl;

    std::cout << std::endl;

    std::cout << p->ToString() << std::endl;
    std::cout << p2.ToString() << std::endl;
    std::cout << p3.ToString() << std::endl;

    delete p;

    _CrtDumpMemoryLeaks();
    return 0;
}

