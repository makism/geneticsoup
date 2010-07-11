

namespace GeneticSoup {

#ifdef _WIN32
	template<class T>
	unsigned long int Genome<T>::_idCounter = 0;
#endif

	template<class T>
	Genome<T>::Genome( unsigned int size, EncodingType type )
		: Pool( size ) {
			Init( );

		mSize = size;
		mEncodingType = type;
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

	template<class T>
	T Genome<T>::operator []( int i ) {
		if( i < mSize ) {
			return mPool->at( i );
		}

		return NULL;
	}

	template<class T>
	const std::string Genome<T>::ToString( bool expandGenome ) {
		std::ostringstream oss;

		oss << " #" << mId;
		oss << " (Fitness: " << mFitness << ") ";

		if( expandGenome ) {
			oss << Pool<T>::ToString( );
		}
		
		return oss.str( );
	}

}
