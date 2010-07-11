#ifndef _NATURALNUMBERGENOME_HPP_
#define _NATURALNUMBERGENOME_HPP_


namespace GeneticSoup {

	class NaturalNumberGenome: public Genome<unsigned int> {

	public:
#pragma region Max/Min/Padding
		static unsigned int Max;
		static unsigned int Min;
		static unsigned int Pad;
#pragma endregion

#pragma region Ctors/Dtors
		NaturalNumberGenome( unsigned int, EncodingType );
		~NaturalNumberGenome( void );
#pragma endregion

		friend void Evaluate( NaturalNumberGenome& );

	protected:
		void RandomEncoding( void );
		void PermutationEncoding( void );
		void CustomEncoding( void );

	};

}

#endif
