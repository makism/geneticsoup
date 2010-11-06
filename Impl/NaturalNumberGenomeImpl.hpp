

namespace GeneticSoup
{

#ifdef _WIN32
	unsigned int NaturalNumberGenome::Max = std::numeric_limits<unsigned int>::max();
	unsigned int NaturalNumberGenome::Min = std::numeric_limits<unsigned int>::min();
	unsigned int NaturalNumberGenome::Pad = 0;
#endif

	NaturalNumberGenome::NaturalNumberGenome(void)
		: Genome()
	{

	}

	NaturalNumberGenome::NaturalNumberGenome(unsigned int size)
		: Genome(size)
	{

	}

	NaturalNumberGenome::~NaturalNumberGenome(void)
	{

	}

	void NaturalNumberGenome::Generate(void)
	{

	}

}
