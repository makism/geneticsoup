#ifndef _GENOME_HPP_
#define _GENOME_HPP_


namespace GeneticSoup {

	template<class T>
	class Genome: public Pool<T> {

	public:
		Genome( int, EncodingType );
		virtual ~Genome( void );

		void Create( void );
		float Fitness( void );
		int Size( void );
		int Id( void );
		bool IsMutated( void );
		bool HasSuccessCrossover( void );
		bool IsCreated( void );

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
