

namespace GeneticSoup {

#ifdef _WIN32
	float RealNumberGenome::Pad = 0.0f;
	float RealNumberGenome::Scale = 1.0f;
#endif

	RealNumberGenome::RealNumberGenome( int size, EncodingType type )
		: Genome( size, type ) {

	}

	RealNumberGenome::~RealNumberGenome( void ) {

	}

	void RealNumberGenome::RandomEncoding( void ) {
		float base = 0.0f;
		float fine = 0.0f;
		int scale = RAND_MAX + 1;

		for( int i=0; i<size; i++ ) {
			base = rand( ) / static_cast<float>( scale );
			fine = rand( ) / static_cast<float>( scale );
	            
			(*pool)[i] = ( ( base + ( fine / scale ) ) * Scale ) + Pad;
		}
	}

	void RealNumberGenome::PermutationEncoding( void ) {

	}

	void RealNumberGenome::CustomEncoding( void ) {

	}

}
