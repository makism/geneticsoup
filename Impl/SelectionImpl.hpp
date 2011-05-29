

namespace GeneticSoup {

    template<class T>
    T Selection<T>::RouletteWheel(Population<T>& pop) {
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

}
