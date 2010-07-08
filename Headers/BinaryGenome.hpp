#ifndef _BINARYGENOME_HPP_
#define _BINARYGENOME_HPP_


namespace GeneticSoup {

	class BinaryGenome: public Genome<unsigned short int> {

	public:
		BinaryGenome( int, EncodingType );
		~BinaryGenome( void );

	protected:
		void RandomEncoding( void );
		void PermutationEncoding( void );

	};

}


#endif
