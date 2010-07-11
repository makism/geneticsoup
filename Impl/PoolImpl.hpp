

namespace GeneticSoup {

	template<class T>
	Pool<T>::Pool( void )
		: mPosition( -1 ) {
		mPool = new std::vector<T>( );
	}

	template<class T>
	Pool<T>::Pool( unsigned int size )
		: mPosition( -1 ) {
		mPool = new std::vector<T>( size );
	}

	template<class T>
	Pool<T>::~Pool( void ) {
		delete mPool;
	}

	template<class T>
	T Pool<T>::At( int i ) {
		return mPool->at( i );
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
	T Pool<T>::Current( void ) {
		return mPool->at( mPosition );
	}

	template<class T>
	void Pool<T>::Reset( void ) {
		mPosition = -1;
	}

	template<class T>
	T Pool<T>::First( void ) {
		if( mPool->size( ) > 0 ) {
			return mPool->at( 0 );
		}
	}
	
	template<class T>
	T Pool<T>::Last( void ) {
		if( mPool->size( ) > 0 ) {
			return mPool->at( mPool->size( ) - 1 );
		}
	}

	template<class T>
	int Pool<T>::Size( void ) {
		return mPool->size( );
	}

	template<class T>
	std::vector<T>* Pool<T>::Reference( void ) {
		return mPool;
	}

	template<class T>
	T Pool<T>::operator []( int i ) {
		if( i < mPool->size( ) ) {
			return mPool->at( i );
		}

		return NULL;
	}

	template<class T>
	const std::string Pool<T>::ToString( void ) {
		std::ostringstream oss;
		int size = mPool->size( );

		oss << "[ ";

		for( int i=0; i<size; i++ ) {
			oss << mPool->at(i);

			if( i<size-1 ) {
				oss << ", ";
			}
		}

		oss << " ]";

		return oss.str( );
	}

}
