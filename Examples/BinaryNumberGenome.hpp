#ifndef _BINARYNUMBER_HPP
#define _BINARYNUMBER_HPP

#include <string>
#include <algorithm>
#include <time.h>
#include <math.h>
#include <iostream>
#include <string>
#include <bitset>
#include <limits>
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
        float result = 0.0f;
        int hits = 0;
        bool continuous = true;
        
        std::stringstream ss;
        for (int i=0; i<Size(); i++) {
            ss << this->At(i);
            
            if (this->At(i)==1 && continuous)
                hits++;
            else
                continuous = false;
        }
        
        mNumber = std::bitset<std::numeric_limits<unsigned long>::digits>(ss.str()).to_ulong();
        
        result = hits * 0.2f;
        result *= 0.5f;
        result += (mNumber / 1023.0f) * 0.5f;
        
        return result;
    }
    
private:
    unsigned int mNumber;
};

#endif
