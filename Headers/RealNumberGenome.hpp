#ifndef _REALNUMBERGENOME_HPP_
#define _REALNUMBERGENOME_HPP_


namespace GeneticSoup {

	class RealNumberGenome: public Genome<float> {

	public:
#pragma region Pad/Scale
		static float Pad;
		static float Scale;
#pragma endregion

		RealNumberGenome( int, EncodingType );
		~RealNumberGenome( void );

	protected:
		void RandomEncoding( void );
		void PermutationEncoding( void );
		void CustomEncoding( void );

	};

}

#endif
