#ifndef _SELECTION_HPP_
#define _SELECTION_HPP_


namespace GeneticSoup {

template<class T>
class Selection {

public:
    static T RouletteWheel(Population<T>&);
    static T RouletteWheel(Population<T>*);
    static void Elitism(Population<T>&, Population<T>&, unsigned int);
    static void Elitism(Population<T>*, Population<T>*, unsigned int);
//     static T Tournament(Population<T>&, unsigned int);
//         static void BinaryTournament(void);
//         static void PropBinaryTournament(void);
};

}

#endif
