

namespace GeneticSoup
{
    
    template<class T>
    const float Mutation<T>::MUTATION_RATE = 0.2f;
    
//     template<class T>
//     Mutation<T>::Mutation(void)
//         : mGenome(0),
//             mMutationOp(Exchange2)
//     {
//         
//     }
//     
//     template<class T>
//     Mutation<T>::~Mutation(void)
//     {
//         mGenome = 0;
//     }
//     
//     template<class T>
//     bool Mutation<T>::Mutate(void)
//     {
//         switch (mMutationOp) {
//             case Invert:
//                 
//                 break;
//             case Insert:
//                 
//                 break;
//             case Shift:
//                 
//                 break;
//             case Exchange2:
//             default:
//                 _Exchange2(this);
//                 break;
//         }
//     }
//     
//     template<class T>
//     void Mutation<T>::SetMutationOp(Operator op)
//     {
//         mMutationOp = op;
//     }
//     
//     template<class T>
//     void Mutation<T>::operator()(void) const
//     {
//         Mutate();
//     }
    
    template<class T>
    void Mutation<T>::_Exchange2(T& genome)
    {
        if (Helpers::Random::Instance()->Generate() < MUTATION_RATE) {
            genome.mIsMutated = true;
            
            int pos1 = Helpers::Random::Instance()->Generate(0, genome.Size() - 1);
            int pos2 = pos1;
            
            while (pos2==pos1)
                pos2 = Helpers::Random::Instance()->Generate(0, genome.Size() - 1);
            
            typename T::mType chromo1 = genome.At(pos1);
            typename T::mType chromo2 = genome.At(pos2);
            
            genome.Assign(pos1, chromo2);
            genome.Assign(pos2, chromo1);
        }
    }
    
    template<class T>
    void Mutation<T>::_Invert(T& genome)
    {
        genome.mIsMutated = true;
        genome[0] = !genome[0];
    }
}
