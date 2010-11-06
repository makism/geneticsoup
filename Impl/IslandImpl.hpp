

namespace GeneticSoup
{

    template<class T>
    Island<T>::Island(void)
    {
    }

    template<class T>
    Island<T>::Island(unsigned int Epochs, unsigned int PopulationSize, unsigned int GenomeSize)
        : mEpochs(Epochs),
          mCurrentEpoch(0),
          mPopulationSize(PopulationSize),
          mGenomeSize(GenomeSize)
    {

        mCurrentPopulation = new Population<T>(mPopulationSize);
        mPreviousPopulation = new Population<T>(mPopulationSize);
        mSelection = new Selection<T>();
    }

    template<class T>
    Island<T>::~Island(void)
    {
        delete mCurrentPopulation;
        delete mPreviousPopulation;
        delete mSelection;
    }

    template<class T>
    void Island<T>::AdvanceEpoch(void)
    {
        if (mCurrentEpoch < mEpochs)
            mCurrentEpoch++;
    }

    template<class T>
    Population<T>* Island<T>::CurrentPopulation(void)
    {
        return mCurrentPopulation;
    }

    template<class T>
    Population<T>* Island<T>::PreviousPopulation(void)
    {
        return mPreviouPopulation;
    }

}
