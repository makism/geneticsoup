

namespace GeneticSoup
{

template<class T>
Island<T>::Island(unsigned int Epochs, unsigned int PopulationSize, unsigned int GenomeSize)
        : mEpochs(Epochs),
        mCurrentEpoch(0),
        mPopulationSize(PopulationSize),
        mGenomeSize(GenomeSize)
{
    mCurrentPopulation = new Population<T>(mPopulationSize);
    mPreviousPopulation = 0;
}

template<class T>
Island<T>::Island(unsigned int Epochs, unsigned int PopulationSize, unsigned int GenomeSize, float MutationRate, float CrossoverRate)
        : mEpochs(Epochs),
        mCurrentEpoch(0),
        mPopulationSize(PopulationSize),
        mGenomeSize(GenomeSize)
{
    mCurrentPopulation = new Population<T>(mPopulationSize);
    mPreviousPopulation = 0;

    SetMutationRate(MutationRate);
    SetCrossoverRate(CrossoverRate);
}

template<class T>
Island<T>::~Island(void)
{
    delete mCurrentPopulation;
    delete mPreviousPopulation;
}

template<class T>
unsigned int Island<T>::Epochs(void) const
{
    return mEpochs;
}

template<class T>
unsigned int Island<T>::Epoch(void) const
{
    return mCurrentEpoch;
}

template<class T>
unsigned int Island<T>::PopulationSize(void) const
{
    return mPopulationSize;
}

template<class T>
void Island<T>::Go(void)
{
    for (unsigned int epoch = 0; epoch<mEpochs; epoch++) {
        AdvanceEpoch();
    }
}

template<class T>
void Island<T>::AdvanceEpoch(void)
{
    if (mCurrentEpoch < mEpochs) {
        mCurrentEpoch++;

        delete mPreviousPopulation;

        mPreviousPopulation = mCurrentPopulation;
        mCurrentPopulation = new Population<T>(mPopulationSize);

        // Copy elite genomes.
        if (mEliteCopies && mCurrentEpoch > 0)
            mSelection.Elitism(mPreviousPopulation, mCurrentPopulation, mEliteCopies, false);
    }
}

template<class T>
void Island<T>::AutoAdvanceEpoch(void)
{
    Island<T>::AdvanceEpoch();

    for (unsigned int i=mCurrentPopulation->Count(); i<mPopulationSize; i+=2) {
        T parent1 = mSelection.Tournament(mPreviousPopulation, 16);
        T parent2 = mSelection.Tournament(mPreviousPopulation, 16);

        T child1 = new TType();
        child1->Generate();

        T child2 = new TType();
        child2->Generate();

        mCrossover.SinglePointExchange(parent1, parent2, child1, child2);

        child1->Mutate();
        child2->Mutate();

        child1->Evaluate();
        child2->Evaluate();

        mCurrentPopulation->Push(child1);
        mCurrentPopulation->Push(child2);
    }
}

template<class T>
Population<T>* Island<T>::CurrentPopulation(void)
{
    return mCurrentPopulation;
}

template<class T>
Population<T>* Island<T>::PreviousPopulation(void)
{
    return mPreviousPopulation;
}

template<class T>
void Island<T>::SetMutationRate(float rate)
{
    Mutation<T>::MUTATION_RATE = rate;
}

template<class T>
void Island<T>::SetCrossoverRate(float rate)
{
    mCrossover.SetCrossoverRate(rate);
}

template<class T>
void Island<T>::SetEliteCopies(unsigned int copies)
{
    mEliteCopies = copies;
}

}
