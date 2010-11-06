#ifndef _SELECTION_HPP_
#define _SELECTION_HPP_


namespace GeneticSoup {

	template<class T>
	class Selection {

	public:
		Selection( void );
		Selection( Population<T> & );
		virtual ~Selection( void );

		void RouletteWheel( void );
		void Elitism( void );
		void Tournament( void );
		void BinaryTournament( void );
		void PropBinaryTournament( void );

	};

}

#endif
