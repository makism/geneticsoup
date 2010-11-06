#ifndef _CROSSOVER_HPP_
#define _CROSSOVER_HPP_


namespace GeneticSoup {

	template<class T>
	class Crossover {

	public:
		void PermutationExchange1( T, T, T, T );
		void PermutationExchange2( T, T, T, T );
		void UniformExchange( T, T, T, T );
		void HalfUniformExchange( T, T, T, T );

	};
}

#endif
