#ifndef _NATURALNUMBERGENOME_HPP_
#define _NATURALNUMBERGENOME_HPP_


namespace GeneticSoup {

	class NaturalNumberGenome: public Genome<int> {

	public:
		static unsigned int Max;
		static unsigned int Min;
		static unsigned int Pad;

		NaturalNumberGenome( void );
		~NaturalNumberGenome( void );

	protected:
		void RandomEncoding( void );
		void PermutationEncoding( void );

	};

}

#endif
