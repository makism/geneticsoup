

namespace GeneticSoup {
    
    template<class T>
    Crossover<T>::Crossover(void)
        : mCrossoverRate(0.75f)
    {
    }
    
    template<class T>
    Crossover<T>::Crossover(const float& rate)
        : mCrossoverRate(rate)
    {
    }
    
    template<class T>
    void Crossover<T>::SetCrossoverRate(const float& rate)
    {
        
    }
    
    template<class T>
    void Crossover<T>::CrossoverRate(void) const
    {
        return mCrossoverRate;
    }
    
    template<class T>
    void Crossover<T>::SinglePointExchange(T& g1, T& g2, T& off1, T& off2)
    {
        int start = Helpers::Random::Instance()->Generate(0, g1.Size());
        
        std::copy(g1.Ref().begin(), g1.Ref().begin() + start, off1.Ref().begin());
        std::copy(g2.Ref().begin() + start, g2.Ref().end(), off1.Ref().begin() + start);
        
        std::copy(g1.Ref().begin() + start, g1.Ref().end(), off2.Ref().begin() + start);
        std::copy(g2.Ref().begin(), g2.Ref().begin() + start, off2.Ref().begin());
    }
    
    template<class T>
    void Crossover<T>::TwoPointExchange(T& g1, T& g2, T& off1, T& off2)
    {
        int pos1 = 0;
        int pos2 = 0;
        
        while (pos1==g1.Size() - 1 || pos2==pos1) {
            pos1 = Helpers::Random::Instance()->Generate(0, g1.Size() - 2);
            pos2 = Helpers::Random::Instance()->Generate(pos1, g1.Size() - 1);
        }
 
        int temp = 0;
        if (pos1>pos2) {
            temp = pos1;
            
            pos1 = pos2;
            pos2 = temp;
        }
     
        temp = pos2 - pos1;
        std::copy(g1.Ref().begin(), g1.Ref().begin() + pos1, off1.Ref().begin());
        std::copy(g2.Ref().begin() + pos1, g2.Ref().begin() + pos1 + temp, off1.Ref().begin() + pos1);
        std::copy(g1.Ref().begin() + pos2, g1.Ref().end(), off1.Ref().begin() + pos2);
        
        std::copy(g2.Ref().begin(), g2.Ref().begin() + pos1, off2.Ref().begin());
        std::copy(g1.Ref().begin() + pos1, g1.Ref().begin() + pos1 + temp, off2.Ref().begin() + pos1);
        std::copy(g2.Ref().begin() + pos2, g2.Ref().end(), off2.Ref().begin() + pos2);
    }
    
    template<class T>
    void Crossover<T>::UniformExchange(T& g1, T& g2, T& off1, T& off2)
    {
        for (unsigned int i=0; i<g1.Size(); i++ ) {
            if (Helpers::Random::Instance()->Generate() > 0.5f) {
                off1.Assign(i, g1.At(i));
                off2.Assign(i, g2.At(i));
            } else {
                off2.Assign(i, g1.At(i));
                off1.Assign(i, g2.At(i));
            }
        }
    }
    
    template<class T>
    void Crossover<T>::ThreeParentExchange(T& g1, T& g2, T& g3, T& off1)
    {
        for (unsigned int i=0; i<g1.Size(); i++) {
            if (g1.At(i) == g2.At(i))
                off1.Assign(i, g1.At(i));
            else
                off1.Assign(i, g3.At(i));
        }
    }
    
    template<class T>
    void Crossover<T>::ShuffleExchange(T& g1, T& g2, T& off1, T& off2)
    {
        std::vector<typename T::mType> genome1(g1.Ref());
        std::vector<typename T::mType> genome2(g2.Ref());
        
        std::random_shuffle(genome1.begin(), genome1.end());
        std::random_shuffle(genome2.begin(), genome2.end());
        
        g1.Ref().swap(genome1);
        g2.Ref().swap(genome2);
        
        SinglePointExchange(g1, g2, off1, off2);
        
        g1.Ref().swap(genome1);
        g2.Ref().swap(genome2);
    }
}
