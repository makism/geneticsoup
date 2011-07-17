#ifndef _SELECTION_HPP_
#define _SELECTION_HPP_


namespace GeneticSoup {

template<class T>
class Selection {

public:
    static T RouletteWheel(Population<T>&);
    static T RouletteWheel(Population<T>*);
    static void Elitism(Population<T>&, Population<T>&, unsigned int, bool=true);
    static void Elitism(Population<T>*, Population<T>*, unsigned int, bool=true);
    static T Tournament(Population<T>& pop, unsigned int contestants, bool allowDups = true);
    static T Tournament(Population<T>* pop, unsigned int contestants, bool allowDups = true);
    static T Random(Population<T>& pop);
    static T Random(Population<T>* pop);
    static T BinaryTournament(Population<T>& pop);
    static T BinaryTournament(Population<T>* pop);
//         static void PropBinaryTournament(void);
};

}

#endif
