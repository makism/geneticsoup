#ifndef _MUTATION_HPP_
#define _MUTATION_HPP_


namespace GeneticSoup {
	
	template<class T>
	class Mutation {

	public:
		enum Type { Exchange2Mutation, InvertMutation, InsertMutation, ShiftMutation };
		
		T Exchange2( T );
		T Invert( T );
		T Insert( T );
		T Shift( T );
	};

}

#endif
