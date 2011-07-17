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
    Island(unsigned int Epochs, unsigned int PopulationSize, unsigned int GenomeSize, float MutationRate, float CrossoverRate);
    /*! */
    virtual ~Island(void);
    
    /*! */
    void SetMutationRate(float rate);
    /*! */
    void SetCrossoverRate(float rate);
    /*! */
    void SetEliteCopies(unsigned int copies);
    
    /*! */
    virtual void Initialize(void) = 0;
    /*! */
    virtual void AdvanceEpoch(void) = 0;
    /*! */
    virtual void Go(void);
    /*! */
    void AutoAdvanceEpoch(void);
    
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
    
    /*! */
    static bool Store(const std::string& filename);
    /*! */
    static Island<T> Load(const std::string& filename);

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
    /*! */
    unsigned int mEliteCopies;
    
    typedef T Type;
    
    typedef typename Helpers::remove_pointer<T>::type TType;
};

}

#endif
