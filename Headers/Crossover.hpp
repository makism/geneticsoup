#ifndef _CROSSOVER_HPP_
#define _CROSSOVER_HPP_


namespace GeneticSoup {

    template<class T>
    class Crossover {

    public:
        Crossover(void);
        
        static void SinglePointExchange(T&, T&, T& = Genome<T>(), T& = Genome<T>());
        static void TwoPointExchange(T&, T&, T& = Genome<T>(), T& = Genome<T>());
        static void UniformExchange(T&, T&, T& = Genome<T>(), T& = Genome<T>());
        static void ThreeParentExchange(T&, T&, T&, T& = Genome<T>());
        static void ShuffleExchange(T&, T&, T& = Genome<T>(), T& = Genome<T>());
//      static void HalfUniformExchange( T, T, T, T );
        
    };
}

#endif
