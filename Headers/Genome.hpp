#ifndef _GENOME_HPP_
#define _GENOME_HPP_


namespace GeneticSoup {

template<class T>
class Genome: public Pool<T>, public Parent {

public:
    template<class U>
    friend class Mutation;

    template<class R>
    friend R CloneGenome(const R&);

public:
    /*! */
    Genome(void);
    /*! */
    Genome(unsigned int size, Function::FunctionType function = Function::Fitness);
    /*! */
    Genome(const Genome<T>& other);
    /*! */
    virtual ~Genome(void);

    /*! */
    void Create(void);
    /*! */
    void Evaluate(void);
    /*! */
    virtual void Mutate(void);
    /*! */
    float Fitness(void) const;
    /*! */
    unsigned long int Id(void) const;
    /*! */
    bool IsMutated(void) const;
    /*! */
    bool HasSuccessCrossover(void) const;
    /*! */
    bool IsCreated(void) const;
    /*! */
    Function::FunctionType Function(void) const;
    
    Population< Genome<T> >* Parent(void) const;

    virtual const std::string ToString(bool = false);

    virtual bool operator >(const Genome<T> &) const;
    virtual bool operator <(const Genome<T> &) const;
    virtual bool operator ==(const Genome<T> &) const;
    virtual T & operator [](unsigned int);
    virtual T const & operator [](unsigned int) const;

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
    /*! */
    Function::FunctionType mFunction;

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
