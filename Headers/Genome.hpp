#ifndef _GENOME_HPP_
#define _GENOME_HPP_


namespace GeneticSoup {

	template<class T>
	class Genome: public Pool<T> {

	public:
#pragma region Ctors/Dtors
		Genome(void);
		Genome(unsigned int);
        Genome(const Genome&);
		virtual ~Genome(void);
#pragma endregion
		void Create(void);
		void Evaluate(void);
		float Fitness(void);
		unsigned long int Id(void);
		bool IsMutated(void);
		bool HasSuccessCrossover(void);
		bool IsCreated(void);

		//friend float EvaluateCallback( Genome<T> & );
		
		/*void Evaluate( void );
		static void SetEvaluateCallback( float (*EvaluateCallback)( Genome<T> & ) ) {
			EvaluateCb = EvaluateCallback;
		}*/

		virtual const std::string ToString(bool = false);

#pragma region Operator overload
		virtual bool operator >(const Genome<T> &) const;
		virtual bool operator <(const Genome<T> &) const;
		virtual bool operator ==(const Genome<T> &) const;
		virtual T & operator [](unsigned int );
		virtual T const & operator [](unsigned int) const;
#pragma endregion

	protected:
		float mFitness;
		unsigned int mSize;
		unsigned long int mId;
		bool mIsMutated;
		bool mSucessCrossover;
		bool mIsCreated;

		void Init(void);
		virtual void Generate(void) = 0;
		virtual float EvaluateCallback(void) = 0;

	private:
		//static float (Genome<T>::*EvaluateCb)( Genome<T> & );
		static unsigned long int _idCounter;

	};
	
	template<class T>
    std::ostream& operator <<(std::ostream& stream, Genome<T> & genome)
    {
        stream << genome.ToString(true);
        return stream;
    }

}

#endif
