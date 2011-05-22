#ifndef _POPULATION_HPP_
#define _POPULATION_HPP_


namespace GeneticSoup
{
	
    template<typename T>
    class Population: public Pool<T>
    {

    public:
        Population(void);
        Population(int, const std::string& = "");
        virtual ~Population(void);

        const std::string Name(void);
        unsigned int Mutations(void);
        unsigned int Crossovers(void);
        unsigned int Migrations(void);
		long unsigned int Id(void);
        
// 		virtual bool Push(const T& value);

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
