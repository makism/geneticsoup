

namespace GeneticSoup {

template<class T>
T Selection<T>::RouletteWheel(Population<T>& pop)
{
    float slice = pop.TotalFitness() * Helpers::Random::Instance()->Generate();
    float total = 0.0f;

    T selectedGenome = 0;
    T currentGenome = 0;

    while (pop.Next()) {
        currentGenome = pop.Current();

        total += currentGenome->Fitness();

        if (total > slice) {
            selectedGenome = currentGenome;
            break;
        }
    }
    pop.Reset();
    
    return selectedGenome;
}

template<class T>
T Selection<T>::RouletteWheel(Population<T>* pop)
{
    return Selection<T>::RouletteWheel(*pop);
}

template<class T>
void Selection<T>::Elitism(Population<T>& pop, Population<T>& newPop, unsigned int copies, bool descending)
{
    if (descending)
        pop.Sort(Population<T>::SortDescending);
    else
        pop.Sort(Population<T>::SortAscending);
    
    for (int i=0; i<copies; i++) {
        T temp = CloneGenome<T>(pop[i]);
        
        newPop.Push(temp);
    }
}

template<class T>
void Selection<T>::Elitism(Population<T>* pop, Population<T>* newPop, unsigned int copies, bool descending)
{
    Selection<T>::Elitism(*pop, *newPop, copies, descending);
}

template<class T>
T Selection<T>::Tournament(Population<T>& pop, unsigned int contestants, bool allowDups)
{
    T genome = 0;
    T randomGenome = 0;
    int index = 0;
    
    for (int i=0; i<contestants; i++) {
        index = Helpers::Random::Instance()->Generate(0, pop.Size() - 1);
        randomGenome = pop.At(index);

        if (genome == 0)
            genome = randomGenome;
        
        if (genome->Function() == Function::Fitness) {
            if (randomGenome->Fitness() > genome->Fitness())
                genome = randomGenome;
        } else {
            if (randomGenome->Fitness() < genome->Fitness())
                genome = randomGenome;
        }
    }
    
    return genome;
}

template<class T>
T Selection<T>::Tournament(Population<T>* pop, unsigned int contestants, bool allowDups)
{
    return Selection<T>::Tournament(*pop, contestants, allowDups);
}

template<class T>
T Selection<T>::Random(Population<T>& pop)
{
    int index = Helpers::Random::Instance()->Generate(0, pop.Size() - 1);
    return pop[index];
}

template<class T>
T Selection<T>::Random(Population<T>* pop)
{
    return Selection<T>::Random(*pop);
}

}
