#ifndef _NATURALNUMBERGENOME_HPP_
#define _NATURALNUMBERGENOME_HPP_


namespace GeneticSoup {

	class NaturalNumberGenome: public Genome<int> {

	public:
		NaturalNumberGenome( void );
		~NaturalNumberGenome( void );

		void Create( void );

	protected:
		void RandomEncoding( void );
		void PermutationEncoding( void );

	};

}

#endif
