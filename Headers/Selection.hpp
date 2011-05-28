#ifndef _SELECTION_HPP_
#define _SELECTION_HPP_


namespace GeneticSoup {

template<class T>
class Selection {

public:
    static void RouletteWheel(Population<T>&);
//         static void Elitism(void);
//         static void Tournament(void);
//         static void BinaryTournament(void);
//         static void PropBinaryTournament(void);
};

}

#endif
