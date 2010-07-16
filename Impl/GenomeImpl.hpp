

namespace GeneticSoup {

	template<class T>
	std::ostream &operator <<( std::ostream &stream, Genome<T> genome )  {
		stream << genome.ToString( true );
		return stream;
	}

#ifdef _WIN32
	template<class T>
	unsigned long int Genome<T>::_idCounter = 0;
#endif

	template<class T>
	Genome<T>::Genome( void ) {

	}

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
	bool Genome<T>::HasSuccessCrossover( void ) {
		return mSucessCrossover;
	}

	template<class T>
	float Genome<T>::Fitness( void ) {
		return mFitness;
	}

	template<class T>
	unsigned long int Genome<T>::Id( void ) {
		return mId;
	}

	template<class T>
	bool Genome<T>::IsMutated( void ) {
		return mIsMutated;
	}

	template<class T>
	bool Genome<T>::IsCreated( void ) {
		return mIsCreated;
	}

	template<class T>
	Genome<T> Genome<T>::operator +( const Genome<T> & other ) const {
		return other;
	}

	template<class T>
	T & Genome<T>::operator []( unsigned int i ) {
		if( i < mSize ) {
			return mPool->at( i );
		} else {
			throw std::invalid_argument( "Index out of boundaries." );
		}
	}

	template<class T>
	T const & Genome<T>::operator []( unsigned int i ) const {
		if( i < mSize ) {
			return mPool->at( i );
		} else {
			throw std::invalid_argument( "Index out of boundaries." );
		}
	}

	template<class T>
	bool Genome<T>::operator >( const Genome<T> & other ) const {
		return ( mFitness > other.mFitness );
	}

	template<class T>
	bool Genome<T>::operator <( const Genome<T> & other ) const {
		return ( mFitness < other.mFitness );
	}

	template<class T>
	bool Genome<T>::operator ==( const Genome<T> & other ) const {
		for( unsigned int i = 0; i<mSize; i++ ) {
			if( (*mPool)[i] != (*(other.mPool))[i] )
				return false;
		}

		return true;
	}

	template<class T>
	const std::string Genome<T>::ToString( bool expandGenome ) {
		std::ostringstream oss;

		oss << "Genome #" << mId;
		oss << " (Fitness: " << mFitness << ") ";

		if( expandGenome ) {
			oss << Pool<T>::ToString( );
		}
		
		return oss.str( );
	}

}
