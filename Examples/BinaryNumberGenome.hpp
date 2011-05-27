#ifndef _BINARYNUMBER_HPP
#define _BINARYNUMBER_HPP

#include <string>
#include <algorithm>
#include <time.h>
#include <math.h>

#include "GeneticSoup.hpp"

using namespace GeneticSoup;


class BinaryNumberGenome: public BinaryGenome {
    
public:
    BinaryNumberGenome(void)
    : BinaryGenome(10)
    {
        this->Create();
        this->Evaluate();
    }
    
    float EvaluateCallback(void)
    {
        return 0.0f;
    }
};

#endif
