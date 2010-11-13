

namespace GeneticSoup
{

    template<class T>
    std::ostream& operator <<(std::ostream& stream, Pool<T> & pool)
    {
        stream << pool.ToString();
        return stream;
    }

#pragma region Ctor/Dtors
    /* Empty ctor.
     *
     * The size of the pool is not specific and can grow.
     */
    template<class T>
    Pool<T>::Pool(void)
        : mHasFixedSize(false),
          mPosition(-1),
          mSize(-1),
          mPushPosition(0),
          mIsEmpty(true)
    {

        mPool = new std::vector<T>();
    }

    /* Default ctor.
     *
     * The pool created has a specific size and cannot grow larger.
     */
    template<class T>
    Pool<T>::Pool(unsigned int size)
        : mPosition(-1),
          mSize(size),
          mPushPosition(0),
          mIsEmpty(true)
    {

        if (size == -1) {
            mHasFixedSize = false;
            mPool = new std::vector<T>();

        } else {
            mHasFixedSize = true;
            mPool = new std::vector<T>(size);
        }
    }

    /* Default dtor.
     *
     */
    template<class T>
    Pool<T>::~Pool(void)
    {
        mPool->clear();
        delete mPool;
    }
#pragma endregion

    /* Returns a reference to the object at the specific position.
     *
     */
    template<class T>
    T& Pool<T>::At(unsigned int i)
    {
        return mPool->at(i);
    }

    /* Assigns the value (by reference) to the specific position of the pool.
     *
     */
    template<class T>
    void Pool<T>::Assign(unsigned int index, T& value)
    {
        if (index < mPool->size() - 1 && index >= 0) {
            (*mPool)[index] = value;
            mIsEmpty = false;

        } else {
            throw std::invalid_argument("Index out of boundaries.");
        }
    }

    /* Pushes back (if there is space) the specific value (by reference).
     *
     */
    template<class T>
    bool Pool<T>::Push(T& value)
    {
        if (mHasFixedSize) {
            if (mPushPosition < mSize) {
                (*mPool)[mPushPosition++] = value;
                mIsEmpty = false;

                return true;
            }

        } else {
            mPool->push_back(value);
            mPushPosition++;
        }

        return false;
    }

#pragma region Enumerator-like methods
    /* Moves the internal index by one. Returns a bool value indicating the success of the procedure.
     *
     */
    template<class T>
    bool Pool<T>::Next(void)
    {
        if (mPosition + 1 < mPool->size()) {
            mPosition++;

            return true;

        } else {

            return false;
        }
    }

    /* Returns a reference to the object at the index that is produced by method Next().
     *
     */
    template<class T>
    T& Pool<T>::Current(void)
    {
        return mPool->at(mPosition);
    }

    /* Resets the internal index.
     *
     */
    template<class T>
    void Pool<T>::Reset(void)
    {
        mPosition = -1;
    }
#pragma endregion

    /* Returns a reference to the first object of the pool.
     *
     */
    template<class T>
    T& Pool<T>::First(void)
    {
        if (mPool->size() > 0) {
            return mPool->at(0);

        } else {
            throw std::invalid_argument("Index out of boundaries.");
        }
    }

    /* Returns a reference to the last object of the pool.
     *
     */
    template<class T>
    T& Pool<T>::Last(void)
    {
        if (mPool->size() > 0) {
            return mPool->at(mPool->size() - 1);

        } else {
            throw std::invalid_argument("Index out of boundaries.");
        }
    }

    /* Returns the size of internal pool (std::vector).
     *
     */
    template<class T>
    unsigned int Pool<T>::Size(void) const
    {
        if (mHasFixedSize) {
            return mSize;

        } else {
            return static_cast<unsigned int>(mPool->size());
        }
    }

    /* Returns a bool which indicates whether or not the size of the pool is fixed.
     *
     */
    template<class T>
    bool Pool<T>::HasFixedSize(void)
    {
        return mHasFixedSize;
    }

    /*
     *
     */
    template<class T>
    void Pool<T>::Clear(void)
    {
        mPool->clear();
        delete mPool;
        Reset();
        mIsEmpty = true;
        mPushPosition = 0;
    }

    /*
     *
     */
    template<class T>
    bool Pool<T>::IsEmpty(void)
    {
        return mIsEmpty;
    }

    /* Returns a reference to the internal pool (std::vector).
     *
     */
    template<class T>
    std::vector<T> & Pool<T>::Ref(void)
    {
        return *mPool;
    }

    template<class T>
    bool Pool<T>::Merge(const Pool& other)
    {
        return false;
    }

    /*
     *
     */
    template<class T>
    T& Pool<T>::operator [](unsigned int i)
    {
        if (i < mPool->size() && i >= 0) {
            return mPool->at(i);

        } else {
            throw std::invalid_argument("Index out of boundaries.");
        }
    }

    /*
     *
     */
    template<class T>
    T const& Pool<T>::operator [](unsigned int i) const
    {
        if (i < mPool->size() && i >= 0) {
            return mPool->at(i);

        } else {
            throw std::invalid_argument("Index out of boundaries.");
        }
    }

    /* Returns a string with all the contents of the pool.
     *
     */
    template<class T>
    const std::string Pool<T>::ToString(void)
    {
        std::ostringstream oss;
        size_t size = mPool->size();

        oss << "[";

        if (mHasFixedSize) {
            oss << "Fixed size";

        } else {
            oss << "Dynamic size";
        }

        oss << " Pool: ";

        for (unsigned int i = 0; i < size; i++) {
            oss << mPool->at(i);

            if (i < size - 1) {
                oss << ", ";
            }
        }

        oss << "]";

        return oss.str();
    }

}
