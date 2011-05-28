#ifndef _GENOME_HPP_
#define _GENOME_HPP_


namespace GeneticSoup {

	template<class T>
	class Genome: public Pool<T>, public Parent {
        
    public:
        template<class U>
        friend class Mutation;
        
	public:
		/*! */
		Genome(void);
		/*! */
		Genome(unsigned int);
		/*! */
        Genome(const Genome&);
        /*! */
		virtual ~Genome(void);
		
        /*! */
		void Create(void);
        /*! */
		void Evaluate(void);
        /*! */
		float Fitness(void);
        /*! */
		unsigned long int Id(void);
        /*! */
		bool IsMutated(void);
        /*! */
		bool HasSuccessCrossover(void);
        /*! */
		bool IsCreated(void);
        
		Population< Genome<T> >* Parent(void) const;

		virtual const std::string ToString(bool = false);

		virtual bool operator >(const Genome<T> &) const;
		virtual bool operator <(const Genome<T> &) const;
		virtual bool operator ==(const Genome<T> &) const;
		virtual T & operator [](unsigned int);
		virtual T const & operator [](unsigned int) const;
        
    public:
        Mutation<T> Mutate;
	
	protected:
		void Init(void);
		virtual void Generate(void) = 0;
		virtual float EvaluateCallback(void) = 0;
    
	protected:
        /*! */
		float mFitness;
        /*! */
		unsigned int mSize;
        /*! */
		unsigned long int mId;
        /*! */
		bool mIsMutated;
        /*! */
		bool mSucessCrossover;
        /*! */
		bool mIsCreated;
	
	private:
		/*! */
		static unsigned long int _idCounter;
	};

	template<class T>
    std::ostream& operator <<(std::ostream& stream, Genome<T> & genome)
    {
		stream << genome.ToString(true);
		return stream;
    }
    
    template<class T>
    std::ostream& operator <<(std::ostream& stream, Genome<T> * genome)
	{
		stream << genome->ToString(true);
		return stream;
	}

}

#endif
