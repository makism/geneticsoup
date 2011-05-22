#include "GeneticSoup.hpp"
#include <time.h>
#include <math.h>
#include <algorithm>
#if _WIN32
#	define _CRTDBG_MAP_ALLOC
#	include <crtdbg.h>
#endif


using namespace GeneticSoup;

class StrGenome: public Genome<std::string>
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
	
    Population<StrGenome*> *population = new Population<StrGenome*>(10, "Initial");
	
	for (unsigned int i=0; i<population->Size(); i++) {
		StrGenome* g = new StrGenome();
		g->Create();
		g->Evaluate();
		
		population->Push(g);
		
		// The same effect:
		// (*population)[i] = g;
		// for:
		// population->Assign(i, g);
	}

// 	std::cout << population << std::endl;
// 
// 	while (population->Next())
// 		std::cout << population->Current() << std::endl;


//     delete population;

#if _WIN32
	_CrtDumpMemoryLeaks();
#endif
	return 0;
}
