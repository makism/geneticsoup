#ifndef _POOL_HPP_
#define _POOL_HPP_


namespace GeneticSoup {

	template<class T>
	class Pool {

	public:
#pragma region Ctors/Dtors
		Pool( void );
		Pool( unsigned int );
		virtual ~Pool( void );
#pragma endregion

#pragma region Enumeration-like methods
		T At( int );
		bool Next( void );
		T Current( void );
		void Reset( void );
		T First( void );
		T Last( void );
		int Size( void );
		std::vector<T> *Reference( void );
#pragma endregion

		virtual const std::string ToString( void );

#pragma region Operator overload
		virtual T operator []( int );
#pragma endregion

	protected:
		int mPosition;
		unsigned int mSize;
		std::vector<T> *mPool;

	};

}

#endif
