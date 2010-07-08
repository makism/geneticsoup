

namespace GeneticSoup {

#ifdef _WIN32
	template<class T>
	unsigned long int Genome<T>::_idCounter = 0;
#endif

	template<class T>
	Genome<T>::Genome( int size, EncodingType type )
		: Pool( ) {
		Init( );

		this->mSize = size;
		this->mEncodingType = type;
	}

	template<class T>
	Genome<T>::~Genome( void ) {

	}

	template<class T>
	void Genome<T>::Create( void ) {
		if( !mIsCreated ) {

			switch( mEncodingType ) {
				case Random:
					RandomEncoding( );
					break;

				case Permutation:
					PermutationEncoding( );
					break;

				case Custom:
					CustomEncoding( );
					break;
			}

			mIsCreated = true;
		}
	}

	template<class T>
	void Genome<T>::Init( void ) {
		  mFitness = 0.0f;
		  mSize = 0;
		  mId = ++_idCounter;
		  mIsMutated = false;
		  mSucessCrossover = false;
		  mIsCreated = false;
	}

	template<class T>
	void Genome<T>::PermutationEncoding( void ) {
	
	}

	template<class T>
	void Genome<T>::RandomEncoding( void ) {
	
	}

	template<class T>
	void Genome<T>::CustomEncoding( void ) {
	
	}

}
