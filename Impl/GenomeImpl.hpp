

namespace GeneticSoup
{

    template<class T>
    std::ostream& operator <<(std::ostream& stream, Genome<T> & genome)
    {
        stream << genome.ToString(true);
        return stream;
    }

#ifdef _WIN32
    template<class T>
    unsigned long int Genome<T>::_idCounter = 0;
#endif

    /* Empty ctor (used only interally).
     *
     */
    template<class T>
    Genome<T>::Genome(void)
        : Pool()
    {

    }

    /* Copy ctor-like.
     *
     */
    template<class T>
    Genome<T>::Genome(const Genome& g)
        : Pool(g.Size())
    {
        mFitness = g.mFitness;
        mId = g.mId;
        mIsMutated = g.mIsMutated;
        mIsCreated = g.mIsCreated;
        mSucessCrossover = g.mSucessCrossover;

        for (int i = 0; i < g.Size(); i++) {
            (*mPool)[i] = g[i];
        }
    }

    /* Default ctor.
     *
     * For the time being it only accepts the total number of genes.
     */
    template<class T>
    Genome<T>::Genome(unsigned int size)
        : Pool(size)
    {
        Init();

        mSize = size;
    }

    /* Empty dtor.
     *
     * Nothing to delete. Pool`s dtor will do the job.
     */
    template<class T>
    Genome<T>::~Genome(void)
    {

    }

    /*
     *
     */
    template<class T>
    void Genome<T>::Create(void)
    {
        if (!mIsCreated) {
            Generate();

            mIsCreated = true;
        }
    }

    /* Common initialization code for each ctor.
     *
     */
    template<class T>
    void Genome<T>::Init(void)
    {
        mFitness = 0.0f;
        mSize = 0;
        mId = _idCounter++;
        mIsMutated = false;
        mSucessCrossover = false;
        mIsCreated = false;
    }

    /* Generates the genome.
     *
     */
    template<class T>
    void Genome<T>::Generate(void)
    {

    }

    /*
     *
     */
    template<class T>
    void Genome<T>::Evaluate(void)
    {
        mFitness = EvaluateCallback();
    }

    /* Evaluates the genome.
     *
     */
    template<class T>
    float Genome<T>::EvaluateCallback(void)
    {

    }

    /* Evalute the genome using the friend fuction.
     *
     */
    /*template<class T>
    void Genome<T>::Evaluate( void ) {
    	mFitness = EvaluateCallback( *this );
    }*/

    /*template<class T>
    void Genome<T>::Evaluate( void ) {
    	mFitness = Genome<T>::_EvaluateCb( *this );
    }*/

    /* Returns the crossover status of the genome.
     *
     */
    template<class T>
    bool Genome<T>::HasSuccessCrossover(void)
    {
        return mSucessCrossover;
    }

    /* Returns the fitness score of the genome.
     *
     */
    template<class T>
    float Genome<T>::Fitness(void)
    {
        return mFitness;
    }

    /* Returns the id of the genome.
     *
     */
    template<class T>
    unsigned long int Genome<T>::Id(void)
    {
        return mId;
    }

    /* Returns the mutation status of the genome.
     *
     */
    template<class T>
    bool Genome<T>::IsMutated(void)
    {
        return mIsMutated;
    }

    /* Returns the creation status of the genome.
     *
     */
    template<class T>
    bool Genome<T>::IsCreated(void)
    {
        return mIsCreated;
    }

    /*
     *
     */
    template<class T>
    T& Genome<T>::operator [](unsigned int i)
    {
        if (i < mPool->size() && i >= 0) {
            return mPool->at(i);

        } else {
            throw std::invalid_argument("Index out of boundaries.");
        }
    }

    /*
     *
     */
    template<class T>
    T const& Genome<T>::operator [](unsigned int i) const
    {
        if (i < mPool->size() && i >= 0) {
            return mPool->at(i);

        } else {
            throw std::invalid_argument("Index out of boundaries.");
        }
    }

    /*
     *
     */
    template<class T>
    bool Genome<T>::operator >(const Genome<T> & other) const
    {
        return (mFitness > other.mFitness);
    }

    /*
     *
     */
    template<class T>
    bool Genome<T>::operator <(const Genome<T> & other) const
    {
        return (mFitness < other.mFitness);
    }

    /*
     *
     */
    template<class T>
    bool Genome<T>::operator ==(const Genome<T> & other) const
    {
        for (unsigned int i = 0; i < mSize; i++) {
            if ((*mPool)[i] != (*(other.mPool))[i])
                return false;
        }

        return true;
    }

    /*
     *
     */
    template<class T>
    const std::string Genome<T>::ToString(bool expandGenome)
    {
        std::ostringstream oss;

        oss << "Genome #" << mId;
        oss << " (Fitness: " << mFitness << ") ";

        if (expandGenome) {
            oss << Pool<T>::ToString();
        }

        return oss.str();
    }

}
