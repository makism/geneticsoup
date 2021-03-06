

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
#ifndef GENETICSOU_NO_ID_COUNTER
        mId(_idCounter++),
#else
        mId(0),
#endif
        mName(name),
        mMutations(0),
        mCrossovers(0),
        mMigrations(0),
        mTotalFitness(0.0f),
        mBestFitness(0.0f),
        mWorstFitness(0.0f),
        mAvgFitness(0.0f),
        mWorstGenome(0),
        mBestGenome(0)
{

}

template<class T>
Population<T>::~Population(void)
{
    typename std::vector<T>::iterator it;

    for (it=this->mPool->begin(); it<this->mPool->end(); it++ )
        delete(*it);

    mBestGenome = 0;
    mWorstGenome = 0;
}

template<class T>
const std::string Population<T>::Name(void) const
{
    return mName;
}

template<class T>
unsigned int Population<T>::Mutations(void) const
{
    return mMutations;
}

template<class T>
unsigned int Population<T>::Crossovers(void) const
{
    return mCrossovers;
}

template<class T>
unsigned int Population<T>::Migrations(void) const
{
    return mMigrations;
}

template<class T>
unsigned long int Population<T>::Id(void) const
{
    return mId;
}

template<class T>
void Population<T>::Sort(const SortOrder so)
{
    switch (so) {
    case SortAscending:
        std::sort(this->mPool->begin(), this->mPool->end(), compareGenomesLt<T>());
        break;
    case SortDescending:
        std::sort(this->mPool->begin(), this->mPool->end(), compareGenomesGt<T>());
        break;
    case SortReset:
    default:
        std::sort(this->mPool->begin(), this->mPool->end(), compareGenomesReset<T>());
        break;
    }
}

template<class T>
void Population<T>::AutoPopulate(void)
{
    for (unsigned int i=0; i<this->mSize; i++) {
        typedef typename Helpers::remove_pointer<T>::type type;
        T temp = new type();
        temp->Create();
        temp->Evaluate();

        this->Push(temp);
    }
}

template<class T>
float Population<T>::TotalFitness(void) const
{
    return mTotalFitness;
}

template<class T>
float Population<T>::AverageFitness(void) const
{
    return mAvgFitness;
}

template<class T>
float Population<T>::BestFitness(void) const
{
    return mBestFitness;
}

template<class T>
float Population<T>::WorstFitness(void) const
{
    return mWorstFitness;
}

template<class T>
T Population<T>::BestGenome(void) const
{
    return mBestGenome;
}

template<class T>
T Population<T>::WorstGenome(void) const
{
    return mWorstGenome;
}

template<class T>
bool Population<T>::Push(const T& value)
{
    Parent* p = static_cast<Parent*>(value);
    p->mParent = this;

    mTotalFitness += value->Fitness();
    mAvgFitness = mTotalFitness / this->Size();
    
    if (value->IsMutated())
        mMutations++;

    // Fitness function
    if (value->Function() == Function::Fitness) {
        if (value->Fitness() > mBestFitness) {
            mBestFitness = value->Fitness();
            mBestGenome = value;

            if (mWorstGenome==0) {
                mWorstFitness = mBestFitness;
                mWorstGenome = mBestGenome;
            }
        }

        if (value->Fitness() < mWorstFitness) {
            mWorstFitness = value->Fitness();
            mWorstGenome = value;
        }
        
    // Cost function
    } else {
        if (mBestGenome == 0 && mWorstGenome == 0) {
            mBestGenome = value;
            mBestFitness = value->Fitness();
            
            mWorstGenome = value;
            mWorstFitness = value->Fitness();
        }

        if (value->Fitness() < mBestFitness) {
            mBestFitness = value->Fitness();
            mBestGenome = value;
        }
        
        if (value->Fitness() > mWorstFitness) {
            mWorstFitness = value->Fitness();
            mWorstGenome = value;
        }
    }


    return Pool<T>::Push(value);
}

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
