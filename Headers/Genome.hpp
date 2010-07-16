#ifndef _GENOME_HPP_
#define _GENOME_HPP_


namespace GeneticSoup {

	template<class T>
	class Genome: public Pool<T> {

	public:
#pragma region Ctors/Dtors
		Genome( void );
		Genome( unsigned int, EncodingType );
		virtual ~Genome( void );
#pragma endregion

		void Create( void );
		float Fitness( void );
		unsigned long int Id( void );
		bool IsMutated( void );
		bool HasSuccessCrossover( void );
		bool IsCreated( void );

		friend void Evaluate( Genome<T>& );
		friend void Evaluate( Genome<T>* );
	
		virtual const std::string ToString( bool = false );

#pragma region Operator overload
		virtual Genome<T> operator +( const Genome<T> & ) const;
		virtual bool operator >( const Genome<T> & ) const;
		virtual bool operator <( const Genome<T> & ) const;
		virtual bool operator ==( const Genome<T> & ) const;
		virtual T & operator []( unsigned int );
		virtual T const & operator []( unsigned int ) const;
#pragma endregion

	protected:
		float mFitness;
		unsigned int mSize;
		unsigned long int mId;
		bool mIsMutated;
		bool mSucessCrossover;
		EncodingType mEncodingType;
		bool mIsCreated;

		void Init( void );
		virtual void RandomEncoding( void );
		virtual void PermutationEncoding( void );
		virtual void CustomEncoding( void );

	private:
		static unsigned long int _idCounter;

	};

}

#endif
