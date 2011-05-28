#ifndef _MUTATION_HPP_
#define _MUTATION_HPP_


namespace GeneticSoup {

template<class T>
class Mutation {

public:
    enum Operator { Exchange2, Invert, Insert, Shift };

public:
    template<class U> friend void Custom(T&);

public:
    Mutation(void);
    Mutation(Operator mutationOp);
    bool Mutate(void);

    void operator()(void) const;

protected:
    void PerformMutation(void);

    void _Exchange2(T&);
    void _Invert(T&);
    void _Insert(T&);
    void _Shift(T&);

private:
    typedef T mType;

    Operator mMutationOp;

public:
    static const float MUTATION_RATE;
};

}

#endif
