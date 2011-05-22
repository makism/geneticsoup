#include <Pool.hpp>


namespace GeneticSoup
{

    template<class T>
    unsigned long int Population<T>::_idCounter = 1;

    template<class T>
    Population<T>::Population(void)
        : Pool<T>()
    {

    }

    template<class T>
    Population<T>::Population(int size, const std::string& name)
        : Pool<T>(size),
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
        typename std::vector<T>::iterator it;
        
        for (it=this->mPool->begin(); it<this->mPool->end(); it++ )
            delete(*it);
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
    
//     template<class T>
//     bool Population<T>::Push(const T& value)
// 	{
// // 		Parent p = static_cast<Parent>(value);
// // 		p.mParent = this;
		
// 		return Pool<T>::Push(value);
// 	}

    template<class T>
    const std::string Population<T>::ToString(void)
    {
        std::ostringstream oss;

        oss << "Population #" << mId;

        if (mName != "") {
            oss << " (\"" << mName << "\")";
        }

        oss << " of size " << this->mSize;

        return oss.str();
    }

}
