

namespace GeneticSoup {

#ifdef _WIN32
	unsigned int NaturalNumberGenome::Max = std::numeric_limits<unsigned int>::max( );
	unsigned int NaturalNumberGenome::Min = std::numeric_limits<unsigned int>::min( );
	unsigned int NaturalNumberGenome::Pad = 0;
#endif

	NaturalNumberGenome::NaturalNumberGenome( int size, EncodingType type )
		: Genome( size, type ) {

	}

	NaturalNumberGenome::~NaturalNumberGenome( void ) {

	}

	void NaturalNumberGenome::RandomEncoding( void ) {
		std::cout << "Max: " << Max << std
			::endl;
		std::cout << "Min: " << Min << std::endl;
		std::cout << "Pad: " << Pad << std::endl;

			unsigned int p = ( ( unsigned int (rand( )) % Max ) + Min ) + Pad;

			std::cout << p << std::endl;
		// base = rand( ) / (float)scale;
		// random.Next(Min, Max) + Pad;
	}

	void NaturalNumberGenome::PermutationEncoding( void ) {

	}

	void NaturalNumberGenome::CustomEncoding( void ) {

	}

}
