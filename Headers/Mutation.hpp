#ifndef _MUTATION_HPP_
#define _MUTATION_HPP_


namespace GeneticSoup {
    
    template<class T>
    class Mutation {
    public:
        enum Type { Exchange2Mutation, InvertMutation, InsertMutation, ShiftMutation };
        
    public:
        static void Exchange2(T&);
        static T& Invert(T&);
        static T& Insert(T&);
        static T& Shift(T&);
    
    public:
        static const float MUTATION_RATE;
    };
    
}

#endif
