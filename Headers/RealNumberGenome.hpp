#ifndef _REALNUMBERGENOME_HPP_
#define _REALNUMBERGENOME_HPP_


namespace GeneticSoup {

	class RealNumberGenome: public Genome<float> {

	public:
		static float Pad;
		static float Scale;

		RealNumberGenome( void );
		~RealNumberGenome( void );

	protected:
		void RandomEncoding( void );
		void PermutationEncoding( void );

	};

}

#endif
