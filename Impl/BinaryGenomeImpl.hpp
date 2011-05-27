

namespace GeneticSoup
{
    
    BinaryGenome::BinaryGenome(void)
    : Genome<short>()
    {
        
    }
    
    BinaryGenome::BinaryGenome(unsigned int size)
    : Genome<short>(size)
    {
        
    }
    
    BinaryGenome::~BinaryGenome(void)
    {
        
    }
    
    void BinaryGenome::Generate(void)
    {
        for (int i=0; i<mSize; i++) {
            if(Helpers::Random::Instance()->Generate() > 0.5f)
                this->Push(0);
            else
                this->Push(1);
        }
    }
    
}


