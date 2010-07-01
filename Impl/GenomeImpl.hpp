

namespace GeneticSoup {

	template<class T>
	Genome<T>::Genome( void )
		: mFitness( 0.0f ), mSize( 0 ), mIsMutated( false ),
			mSucessCrossover( false ), mPermutationEncoding( false ),
			mIsCreated( false ) {

	}

	template<class T>
	Genome<T>::~Genome( void ) {

	}

	template<class T>
	void Genome<T>::Create( void ) {
		if( !mIsCreated ) {
			if( mPermutationEncoding ) {
				PermutationEncoding( );
			} else {
				RandomEncoding( );
			}

			mIsCreated = true;
		}
	}

}
