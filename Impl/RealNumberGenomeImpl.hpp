

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
		/*
		    float base = 0.0f;
            float fine = 0.0f;
            for( int i=0; i<dimensions; i++ ) {
            base = rand( ) / (float)scale;
            fine = rand( ) / (float)scale;
                
            points[i] = base + ( fine / scale );
		*/
		// ((float)random.NextDouble() * scale) + pad;
	}

	void RealNumberGenome::PermutationEncoding( void ) {

	}

}
