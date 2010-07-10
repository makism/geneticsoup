#ifndef _POOL_HPP_
#define _POOL_HPP_


namespace GeneticSoup {

	template<class T>
	class Pool {

	public:
		Pool( void );
		Pool( int );
		virtual ~Pool( void );

		T At( int );
		bool MoveNext( void );
		T Current( void );
		void Reset( void );
		int Size( void );
		std::vector<T> *Reference( void );

		virtual const std::string ToString( void );

#pragma region Operator overload
		virtual T operator []( int );
#pragma endregion

	protected:
		int position;
		int size;
		std::vector<T> *pool;

	};

}

#endif
