

namespace GeneticSoup {

#ifdef _WIN32
	unsigned int NaturalNumberGenome::Max = std::numeric_limits<unsigned int>::max( );
	unsigned int NaturalNumberGenome::Min = std::numeric_limits<unsigned int>::min( );
	unsigned int NaturalNumberGenome::Pad = 0;
#endif

	NaturalNumberGenome::NaturalNumberGenome( unsigned int size, EncodingType type )
		: Genome( size, type ) {

	}

	NaturalNumberGenome::~NaturalNumberGenome( void ) {

	}

	void NaturalNumberGenome::RandomEncoding( void ) {
		for( int i=0; i<Size( ); i++ ) {
			(*mPool)[i] = (( static_cast<unsigned int> (rand( )) % Max ) + Min ) + Pad;
		}
	}

	void NaturalNumberGenome::PermutationEncoding( void ) {

	}

	void NaturalNumberGenome::CustomEncoding( void ) {

	}

}
