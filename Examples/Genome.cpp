#include "GeneticSoup.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace GeneticSoup;


class StrGenome: public GeneticSoup::Genome<std::string>
{

public:
    StrGenome(void)
        : Genome<std::string>(5) {

    }

    void Generate(void) {
        for (unsigned int i = 0; i < mSize; i++) {
            std::ostringstream oss;

            for (unsigned int x = 0; x < mSize; x++) {
                char ch = (char)((rand() % 25) + 65);
                oss << ch;
            }
            
            std::string temp = oss.str();
            this->Push(temp);
        }
    }

    float EvaluateCallback(void) {
        int hits = 0;
        char curr;

        for (unsigned int i = 0; i < mSize; i++) {
            std::string str = this->At(i);

            for (unsigned int x = 0; x < mSize; x++) {
                curr = str.at(x);

                if (curr == 'A') {
                    hits++;
                }
            }
        }

        return static_cast<float>(static_cast<float>(hits) / (mSize * mSize));
    }
};


int main(int argc, char** argv)
{
    time_t seconds;
    time(&seconds);

    srand((unsigned int) seconds);
    rand();

    StrGenome strg;
    strg.Create();
    strg.Evaluate();
// 
//     std::cout << strg.ToString(true) << std::endl;
// 
//     StrGenome strg2(strg);
//     std::cout << strg2.ToString(true) << std::endl;

    std::cin.get();
    return 0;
}
