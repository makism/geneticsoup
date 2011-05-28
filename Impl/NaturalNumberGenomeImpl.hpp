

namespace GeneticSoup
{

	unsigned int NaturalNumberGenome::Max = std::numeric_limits<unsigned int>::max();
	unsigned int NaturalNumberGenome::Min = std::numeric_limits<unsigned int>::min();
	unsigned int NaturalNumberGenome::Pad = 0;

	NaturalNumberGenome::NaturalNumberGenome(void)
		: Genome<unsigned int>()
	{

	}

	NaturalNumberGenome::NaturalNumberGenome(unsigned int size)
		: Genome<unsigned int>(size)
	{

	}

	NaturalNumberGenome::~NaturalNumberGenome(void)
	{

	}

	void NaturalNumberGenome::Generate(void)
	{

	}

}
