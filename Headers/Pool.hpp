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

#pragma region Enumeration-like and Vector-modifiers/accessors methods
		T & At( unsigned int );
		void Assign( unsigned int, T );
		bool Push( T );
		bool Next( void );
		T Current( void );
		void Reset( void );
		T First( void );
		T Last( void );
		unsigned int Size( void );
		std::vector<T> *Reference( void );
#pragma endregion

		virtual const std::string ToString( void );

#pragma region Operator overload
		virtual T operator []( unsigned int );
#pragma endregion

	protected:
		unsigned int mPosition;
		unsigned int mPushPosition;
		unsigned int mSize;
		std::vector<T> *mPool;

	};

}

#endif
