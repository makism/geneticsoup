#ifndef _NATURALNUMBERGENOME_HPP_
#define _NATURALNUMBERGENOME_HPP_


namespace GeneticSoup
{

	class NaturalNumberGenome: public Genome<unsigned int>
	{

	public:
#pragma region Max/Min/Padding
		static unsigned int Max;
		static unsigned int Min;
		static unsigned int Pad;
#pragma endregion

#pragma region Ctors/Dtors
		NaturalNumberGenome(void);
		NaturalNumberGenome(unsigned int);
		~NaturalNumberGenome(void);
#pragma endregion

		/*friend void Evaluate( NaturalNumberGenome& );
		friend void Evaluate( NaturalNumberGenome* );*/

	protected:
		void Generate(void);
	};

}

#endif
