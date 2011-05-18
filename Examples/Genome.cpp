#include <string>
#include <algorithm> 
#include <time.h>
#include <math.h>

#include "GeneticSoup.hpp"


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

            for (unsigned int x = 0; x < mSize; x++)
                oss << (char)((rand() % 25) + 65);
            
            this->Push(oss.str());
        }
    }

    float EvaluateCallback(void) {
        int hits = std::for_each(this->Ref().begin(), this->Ref().end(), parseString());
		
        return static_cast<float>(static_cast<float>(hits) / (mSize * mSize));
    }
    
private:
    struct parseString {
		int hits;
		
		void operator() (std::string &str) {
			hits += std::count(str.begin(), str.end(), 'A');
		}
		
		operator int() {
			return hits;
		}
	};
};


int main(int argc, char** argv)
{
    time_t seconds;
    time(&seconds);

    srand((unsigned int) seconds);
    rand();

	// Create a new StrGenome and Evaluate it.
    StrGenome strg;
    strg.Create();
    strg.Evaluate();

    std::cout << strg.ToString(true) << std::endl;

	// Copy-ctor.
    StrGenome strg2(strg);
	
    std::cout << strg2.ToString(true) << std::endl;

	
    return 0;
}
