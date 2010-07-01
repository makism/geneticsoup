

namespace GeneticSoup {

	template<class T>
	Pool<T>::Pool( void )
		: position( 0 ), size( -1 ) {
		pool = new std::vector<T>( );
	}

	template<class T>
	Pool<T>::Pool( int size )
		: position( 0 ) {
		this->size = size;
		pool = new std::vector<T>( size );
	}

	template<class T>
	Pool<T>::~Pool( void ) {
		delete pool;
	}

	template<class T>
	bool Pool<T>::MoveNext( void ) {
		if( position < pool->size( ) ) {
			position++;

			return true;

		} else {

			return false;

		}
	}

	template<class T>
	T Pool<T>::Current( void ) {
		return pool->at( position );
	}

	template<class T>
	void Pool<T>::Reset( void ) {
		position = 0;
	}

	template<class T>
	int Pool<T>::Size( void ) {
		if( size != -1 ) {
			return size;
		} else {
			return pool->size( );
		}
	}

	template<class T>
	std::vector<T>* Pool<T>::Reference( void ) {
		return pool;
	}

	template<class T>
	T Pool<T>::operator []( int i ) {
		if( i < pool->size( ) ) {
			return pool->at( i );
		}

		return NULL;
	}

}
