#ifndef _ISLAND_HPP_
#define _ISLAND_HPP_


namespace GeneticSoup
{

template<class T>
class Island
{
    
public:
    /*! */
    Island(unsigned int Epochs, unsigned int PopulationSize, unsigned int GenomeSize);
    /*! */
    virtual ~Island(void);

    /*! */
    virtual void Initialize(void) = 0;
    /*! */
    virtual void AdvanceEpoch(void) = 0;
    /*! */
    void AutoAdvanceEpoch(void);
    /*! */
    void SetElitism(unsigned int);
    
    
    /*! */
    unsigned int Epochs(void) const;
    /*! */
    unsigned int Epoch(void) const;
    /*! */
    unsigned int PopulationSize(void) const;
    /*! */
    Population<T>* CurrentPopulation(void);
    /*! */
    Population<T>* PreviousPopulation(void);

protected:
    /*! */
    Population<T> *mCurrentPopulation;
    /*! */
    Population<T> *mPreviousPopulation;
    /*! */
    Selection<T> mSelection;
    /*! */
    Crossover<T> mCrossover;
    /*! */
    unsigned int mEpochs;
    /*! */
    unsigned int mCurrentEpoch;
    /*! */
    unsigned int mPopulationSize;
    /*! */
    unsigned int mGenomeSize;
    
    typedef typename Helpers::remove_pointer<T>::type TT;
    
private:
    /*! */
    unsigned int mEliteCopies;
};

}

#endif
