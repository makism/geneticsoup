#ifndef _CROSSOVER_HPP_
#define _CROSSOVER_HPP_


namespace GeneticSoup {

template<class T>
class Crossover {

public:
    Crossover(void);
    Crossover(const float&);

    void SinglePointExchange(T, T, T = new Genome<T>(), T = new Genome<T>());
    void TwoPointExchange(T, T, T = new Genome<T>(), T = new Genome<T>());
    void UniformExchange(T, T, T = new Genome<T>(), T = new Genome<T>());
    void ThreeParentExchange(T, T, T, T = new Genome<T>());
    void ShuffleExchange(T, T, T = new Genome<T>(), T = new Genome<T>());

    void SetCrossoverRate(const float& rate);
    void CrossoverRate(void) const;

private:
    typedef T mType;

private:
    float mCrossoverRate;

};
}

#endif
