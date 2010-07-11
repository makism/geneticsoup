#ifndef _GENOME_HPP_
#define _GENOME_HPP_


namespace GeneticSoup {

	template<class T>
	class Genome: public Pool<T> {

	public:
#pragma region Ctors/Dtors
		Genome( unsigned int, EncodingType );
		virtual ~Genome( void );
#pragma endregion

		void Create( void );
		float Fitness( void );
		int Id( void );
		bool IsMutated( void );
		bool HasSuccessCrossover( void );
		bool IsCreated( void );

		friend void Evaluate( Genome<T>& );
		friend void Evaluate( Genome<T>* );
	
		virtual const std::string ToString( bool = false );

#pragma region Operator overload
		virtual T operator []( int );
#pragma endregion

	protected:
		float mFitness;
		int mSize;
		int mId;
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
