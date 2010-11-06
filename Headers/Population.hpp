#ifndef _POPULATION_HPP_
#define _POPULATION_HPP_


namespace GeneticSoup
{

    template<class T>
    class Population: public Pool<T>
    {

    public:
        Population(void);
        Population(int, std::string = "");
        virtual ~Population(void);

        const std::string Name(void);
        unsigned int Mutations(void);
        unsigned int Crossovers(void);
        unsigned int Migrations(void);
        long unsigned int Id(void);

        virtual const std::string ToString(void);

    private:
        static unsigned long int _idCounter;
        std::string mName;
        unsigned int mMutations;
        unsigned int mCrossovers;
        unsigned int mMigrations;
        unsigned long int mId;
        float mTotalFitness;
        float mBestFitness;
        float mWorstFitness;
        float mAvgFitness;

    };

}

#endif
