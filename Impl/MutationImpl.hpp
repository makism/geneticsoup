

namespace GeneticSoup
{
    
    template<class T>
    const float Mutation<T>::MUTATION_RATE = 0.2f;
    
    template<class T>
    void Mutation<T>::Exchange2(T& genome)
	{
        if (Helpers::Random::Instance()->Generate() < MUTATION_RATE) {
            genome.mIsMutated = true;
            
            int pos1 = Helpers::Random::Instance()->Generate(0, genome.Size());
            int pos2 = pos1;
            
            while (pos2==pos1)
                pos2 = Helpers::Random::Instance()->Generate(0, genome.Size());
        
            typename T::mType chromo1 = genome.At(pos1);
            typename T::mType chromo2 = genome.At(pos2);
            
            genome.Assign(pos1, chromo2);
            genome.Assign(pos2, chromo1);
        }
	}
	
	template<class T>
    T& Mutation<T>::Invert(T& genome)
	{
		return genome;
	}
	
	template<class T>
    T& Mutation<T>::Insert(T& genome)
	{
		return genome;
	}
	
	template<class T>
    T& Mutation<T>::Shift(T& genome)
	{
		return genome;
	}

}
