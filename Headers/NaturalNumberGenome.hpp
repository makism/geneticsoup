#ifndef _NATURALNUMBERGENOME_HPP_
#define _NATURALNUMBERGENOME_HPP_

namespace GeneticSoup
{

class NaturalNumberGenome: public Genome< unsigned int >
{

public:
    static unsigned int Max;
    static unsigned int Min;
    static unsigned int Pad;

    NaturalNumberGenome(void);
    NaturalNumberGenome(unsigned int);
    ~NaturalNumberGenome(void);

protected:
    void Generate(void);
};

}

#endif

