#ifndef _GENOME_HPP_
#define _GENOME_HPP_


namespace GeneticSoup {

	template<class T>
	class Genome: public Pool<T> {

	public:
		Genome( void );
		virtual ~Genome( void );

		void Create( void );

	protected:
		float mFitness;
		int mSize;
		int mId;
		bool mIsMutated;
		bool mSucessCrossover;
		bool mPermutationEncoding;
		bool mIsCreated;

		void Init( void );
		virtual void RandomEncoding( void ) = 0;
		virtual void PermutationEncoding( void ) = 0;

	};

}

#endif
