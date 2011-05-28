#ifndef _ISLAND_HPP_
#define _ISLAND_HPP_


namespace GeneticSoup
{

template<class T>
class Island
{

public:
    Island(void);
    Island(unsigned int, unsigned int, unsigned int);
    virtual ~Island(void);

    virtual void Initialize(void) = 0;
    virtual void AdvanceEpoch(void) = 0;
    unsigned int Epochs(void);
    unsigned int PopulationSize(void);
    Population<T>* CurrentPopulation(void);
    Population<T>* PreviousPopulation(void);

    void SetElitism(unsigned int);

    /*
      Mutation<T>::Type MutationType(void);
      void MutationType(Mutation<T>::Type);*/

protected:
    Population<T> *mCurrentPopulation;
    Population<T> *mPreviousPopulation;
    Selection<T> *mSelection;
//         Mutation *mMutation;
    Crossover<T> *mCrossover;
    unsigned int mEpochs;
    unsigned int mCurrentEpoch;
    unsigned int mPopulationSize;
    unsigned int mGenomeSize;

private:
    unsigned int mEliteCopies;
};

}

#endif
