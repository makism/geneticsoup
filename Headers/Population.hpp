#ifndef _POPULATION_HPP_
#define _POPULATION_HPP_


namespace GeneticSoup
{

template<typename T>
class Population: public Pool<T>
{
    
public:
    enum SortOrder { SortAscending, SortDescending, SortReset };

public:
    /*! */
    Population(void);
    /*! */
    Population(int, const std::string& = "");
    /*! */
    virtual ~Population(void);

    /*! */
    const std::string Name(void) const;
    /*! */
    unsigned int Mutations(void) const;
    /*! */
    unsigned int Crossovers(void) const;
    /*! */
    unsigned int Migrations(void) const;
    /*! */
    long unsigned int Id(void) const;
    
    /*! */
    void Sort(const SortOrder so = SortAscending);
    /*! */
    void AutoPopulate(void);
    
    /*! */
    float TotalFitness(void) const;
    /*! */
    float AverageFitness(void) const;
    /*! */
    float WorstFitness(void) const;
    /*! */
    float BestFitness(void) const;
    
    /*! */
    T BestGenome(void) const;
    /*! */
    T WorstGenome(void) const;

    /*! Overriden method from Pool<T>
     * 
     * When a genome is pushed to the population,
     * we modify it (the genome) by assigning it,
     * the current population (this) as it's parent.
     */
    virtual bool Push(const T& value);

    virtual const std::string ToString(void);

private:
    static unsigned long int _idCounter;
    
    /*! A short descriptive title for the population, like 'initial'. */
    std::string mName;
    /*! The total number of mutations. */
    unsigned int mMutations;
    /*! The total number of crossovers. */
    unsigned int mCrossovers;
    /*! The total number of migrations. */
    unsigned int mMigrations;
    /*! A unique id. */
    unsigned long int mId;
    
    /*! The summary of all genomes' fitnesses. */
    float mTotalFitness;
    /*! The best fitness that a gnome has demonstrated. */
    float mBestFitness;
    /*! The worst fitness that a genome has demonstrated. */
    float mWorstFitness;
    /*! The average fitness. */
    float mAvgFitness;
    
    /*! A pointer to the best genome of the population. */
    T mBestGenome;
    /*! A pointer to the worst genome of the population. */
    T mWorstGenome;
};


template<class T>
struct compareGenomesLt {
    bool operator() (const T& g1, const T& g2) {
        return *g1 < *g2;
    }
};

template<class T>
struct compareGenomesGt {
    bool operator() (const T& g1, const T& g2) {
        return *g1 > *g2;
    }
};

template<class T>
struct compareGenomesReset {
    bool operator() (const T& g1, const T& g2) {
        return g1->Id() < g2->Id();
    }
};

template<class T>
std::ostream& operator <<(std::ostream& stream, Population<T> & population)
{
    stream << population.ToString();
    return stream;
}

template<class T>
std::ostream& operator <<(std::ostream& stream, Population<T> * population)
{
    stream << population->ToString();
    return stream;
}

}

#endif
