

namespace GeneticSoup {

	template<class T>
	std::ostream &operator <<( std::ostream &stream, Pool<T> pool )  {
		stream << pool.ToString( );
		return stream;
	}

	template<class T>
	Pool<T>::Pool( void )
		: mPosition( -1 ), mSize( -1 ), mPushPosition( 0 ) {
		mPool = new std::vector<T>( );
	}

	template<class T>
	Pool<T>::Pool( unsigned int size )
		: mPosition( -1 ), mSize( size ), mPushPosition( 0 ) {
		mPool = new std::vector<T>( size );
	}

	template<class T>
	Pool<T>::~Pool( void ) {
		delete mPool;
	}

	template<class T>
	T & Pool<T>::At( unsigned int i ) {
		return &( mPool->at( i ) );
	}

	template<class T>
	void Pool<T>::Assign( unsigned int index, T & value ) {
		if( index < mPool->size( ) - 1 && index > 0 ) {
			(*mPool)[index] = value;
		} else {
			throw std::invalid_argument( "Index out of boundaries." );
		}
	}

	template<class T>
	bool Pool<T>::Push( T & value ) {
		if( mPushPosition + 1 < mSize ) {
			(*mPool)[mPushPosition++] = value;

			return true;
		}

		return false;
	}

	template<class T>
	bool Pool<T>::Next( void ) {
		if( mPosition + 1 < mPool->size( ) ) {
			mPosition++;

			return true;
		} else {

			return false;
		}
	}

	template<class T>
	T & Pool<T>::Current( void ) {
		return mPool->at( mPosition );
	}

	template<class T>
	void Pool<T>::Reset( void ) {
		mPosition = -1;
	}

	template<class T>
	T & Pool<T>::First( void ) {
		if( mPool->size( ) > 0 ) {
			return mPool->at( 0 );
		}
	}
	
	template<class T>
	T & Pool<T>::Last( void ) {
		if( mPool->size( ) > 0 ) {
			return mPool->at( mPool->size( ) - 1 );
		}
	}

	template<class T>
	unsigned int Pool<T>::Size( void ) {
		return mPool->size( );
	}

	template<class T>
	std::vector<T>* Pool<T>::Reference( void ) {
		return mPool;
	}

	template<class T>
	T Pool<T>::operator []( unsigned int i ) {
		if( i < mPool->size( ) ) {
			return mPool->at( i );
		} else {
			throw std::invalid_argument( "Index out of boundaries." );
		}
	}

	template<class T>
	const std::string Pool<T>::ToString( void ) {
		std::ostringstream oss;
		int size = mPool->size( );

		oss << "[Pool: ";

		for( int i=0; i<size; i++ ) {
			oss << mPool->at(i);

			if( i<size-1 ) {
				oss << ", ";
			}
		}

		oss << "]";

		return oss.str( );
	}

}
