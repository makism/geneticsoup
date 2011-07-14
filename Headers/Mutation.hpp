#ifndef _MUTATION_HPP_
#define _MUTATION_HPP_


namespace GeneticSoup {
    
// template<class P>
// class Genome;
    
template<class T>
class Mutation {

public:
//     enum Operator { Exchange2, Invert, Insert, Shift };

// public:
//     template<class U> friend void Custom(T&);

public:
//     Mutation(void);
//     ~Mutation(void);
    
//     bool Mutate(void);
//     void SetMutationOp(Operator op);
// 
//     void operator()(void) const;

    static void _Exchange2(T&);
    static void _Invert(T&);
    
// protected:
//     void _Insert(T&);
//     void _Shift(T&);
// 
// private:
//     typedef T mType;
// 
//     Operator mMutationOp;
//     
//     Genome<T>* mGenome;

public:
    static const float MUTATION_RATE;
};

}

#endif
