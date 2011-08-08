#ifndef _POOL_HPP_
#define _POOL_HPP_


namespace GeneticSoup
{
/*! \brief Pool is a specialized frontend to std::vector. */
template<class T>
class Pool
{

public:
    /*! Intantiates a Pool with dynamic size. */
    Pool(void);

    /*! Intantiates a fixed-size Pool.
     * \param size The size of the pool
     */
    Pool(unsigned int size);

    /*! Destroy the Pool and clean the memory. */
    virtual ~Pool(void);

    bool Next(void);
    T& Current(void) const;
    void Reset(void);

    T& At(unsigned int offset);
    void Assign(unsigned int index, const T& value);
    bool Push(const T& value);
    T& First(void) const;
    T& Last(void) const;
    unsigned int Size(void) const;
    bool HasFixedSize(void) const;
    void Clear(void);
    bool IsEmpty(void) const;
    unsigned int Count(void) const;

    /*! Merge a Pool with the current.
     * \param p Source Pool
     * \return Whether the merge has been completed */
    bool Merge(const Pool &p);

    std::vector<T> & Ref(void);
    std::vector<T> * Ptr(void);

    virtual const std::string ToString(void) const;

    virtual T const& operator [](unsigned int) const;
    virtual T& operator [](unsigned int);

public:
    typedef T mType;

protected:
    /*! */
    unsigned int mPosition;
    /*! */
    unsigned int mPushPosition;
    /*! The size of the internal vector. */
    unsigned int mSize;
    /*! The internal vector. */
    std::vector<T> *mPool;
    /*! Indicates whether the internal vector has any children at all. */
    bool mIsEmpty;

private:
    /*! Indicates whether the internal vector has a fixed sized and cannot be resized dynamically. */
    bool mHasFixedSize;
};


template<class T>
std::ostream& operator <<(std::ostream& stream, Pool<T> & pool)
{
    stream << pool.ToString();
    return stream;
}

template<class T>
std::ostream& operator <<(std::ostream& stream, Pool<T> * pool)
{
    stream << pool->ToString();
    return stream;
}

}

#endif
