#ifndef _POOL_HPP_
#define _POOL_HPP_


namespace GeneticSoup {

	/* Pool is lightweight and specialized frontend of std::vector.
	 * 
	 * Although there is the possibility to access the internal
	 * std::vector it not recommended.
	 */
	template<class T>
	class Pool {

	public:
#pragma region Ctors/Dtors
		Pool( void );
		Pool( unsigned int );
		virtual ~Pool( void );
#pragma endregion

#pragma region Enumeration-like methods
		bool Next( void );
		T & Current( void );
		void Reset( void );
#pragma endregion

#pragma region Vector-modifiers/accessors methods
		T & At( unsigned int );
		void Assign( unsigned int, T & );
		bool Push( T & );
		T & First( void );
		T & Last( void );
		unsigned int Size( void ) const;
		bool HasFixedSize( void );
		void Clear( void );
#pragma endregion

#pragma region
		bool Merge( const Pool & );
#pragma endregion

		std::vector<T> & Ref( void );
		std::vector<T> * Ptr( void );

		virtual const std::string ToString( void );

#pragma region Operator overload
		virtual T const& operator []( unsigned int ) const;
		virtual T & operator []( unsigned int );
#pragma endregion

	protected:
		unsigned int mPosition;
		unsigned int mPushPosition;
		unsigned int mSize;
		std::vector<T> *mPool;

        typedef T mType;

	private:

		bool mHasFixedSize;
	};

}

#endif
