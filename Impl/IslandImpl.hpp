

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
void Island<T>::AdvanceEpoch(void)
{
    if (mCurrentEpoch < mEpochs) {
        mCurrentEpoch++;
        
        delete mPreviousPopulation;

        mPreviousPopulation = mCurrentPopulation;
        mCurrentPopulation = new Population<T>(mPopulationSize);
    }
}

template<class T>
void Island<T>::AutoAdvanceEpoch(void)
{
    Island<T>::AdvanceEpoch();

    for (int i=0; i<mPopulationSize; i+=2) {
        T father = mSelection.RouletteWheel(mPreviousPopulation);
        T mother = mSelection.RouletteWheel(mPreviousPopulation);

        T child1 = new TT();
        T child2 = new TT();

        mCrossover.SinglePointExchange(father, mother, child1, child2);

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

}
