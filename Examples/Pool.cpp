#include "GeneticSoup.hpp"
#if _WIN32
#	define _CRTDBG_MAP_ALLOC
#	include <crtdbg.h>
#endif

typedef unsigned long long int uint64;

int main(int argc, char** argv) {
    GeneticSoup::Pool<uint64> pool(10);

	pool.Push(1);		// push 1
	pool.Push(2);		// push 2
	pool.Assign(9, 10); // assign 10 as the last element of the pool
	pool.Push(3);		// push 3

	uint64 &temp = pool.At(2);
	temp = pool.First() + pool[9];

	if (!pool.IsEmpty()) {
		while (pool.Next())	
			std::cout << pool.Current() << std::endl;
		pool.Reset();
	}
	
	// or: std::cout << pool.ToString() << std::endl;

#if _WIN32
	_CrtDumpMemoryLeaks();
#endif
    return 0;
}

