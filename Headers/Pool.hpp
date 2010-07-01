#ifndef _POOL_HPP_
#define _POOL_HPP_


namespace GeneticSoup {

	template<class T>
	class Pool {

	public:
		Pool( void );
		Pool( int );
		~Pool( void );

		bool MoveNext( void );
		T Current( void );
		void Reset( void );
		int Size( void );
		std::vector<T> *Reference( void );

		std::string ToString( void ) {
			std::string str( "asdf ");
			return str;
		}

#pragma region Operator overload
		T operator []( int );
		//friend std::ostream& operator <<( std::ostream &, const Pool );
#pragma endregion

	protected:
		std::vector<T> *pool;

	private:
		int position;
		int size;

	};

}

#endif
