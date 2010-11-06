

namespace GeneticSoup
{

    template<class T>
    std::ostream& operator <<(std::ostream& stream, Population<T> pool)
    {
        stream << pool.ToString();
        return stream;
    }

#ifdef _WIN32
    template<class T>
    unsigned long int Population<T>::_idCounter = 1;
#endif

    template<class T>
    Population<T>::Population(void)
        : Pool()
    {

    }

    template<class T>
    Population<T>::Population(int size, std::string name)
        : Pool(size),
          mId(_idCounter++),
          mName(name),
          mMutations(0),
          mCrossovers(0),
          mMigrations(0),
          mTotalFitness(0.0f),
          mBestFitness(0.0f),
          mWorstFitness(0.0f),
          mAvgFitness(0.0f)
    {

    }

    template<class T>
    Population<T>::~Population(void)
    {

    }

    template<class T>
    const std::string Population<T>::Name(void)
    {
        return mName;
    }

    template<class T>
    unsigned int Population<T>::Mutations(void)
    {
        return mMutations;
    }

    template<class T>
    unsigned int Population<T>::Crossovers(void)
    {
        return mCrossovers;
    }

    template<class T>
    unsigned int Population<T>::Migrations(void)
    {
        return mMigrations;
    }

    template<class T>
    unsigned long int Population<T>::Id(void)
    {
        return mId;
    }

    template<class T>
    const std::string Population<T>::ToString(void)
    {
        std::ostringstream oss;

        oss << "Population #" << mId;

        if (mName != "") {
            oss << " (\"" << mName << "\")";
        }

        oss << " of size " << mSize;

        return oss.str();
    }

}
