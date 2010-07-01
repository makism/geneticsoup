#ifndef _GENOME_HPP_
#define _GENOME_HPP_


namespace GeneticSoup {

	template<class T>
	class Genome: public Pool<T> {

	public:
		Genome( void );
		~Genome( void );

		virtual void Create( void ) = 0;

	protected:
		float _fitness;
		int _size;
		int _id;
		bool _isMutated;
		bool _sucessCrossover;
		bool _permutationEncoding;
		bool _isCreated;

		void Init( void );
		virtual void RandomEncoding( void ) = 0;
		virtual void PermutationEncoding( void ) = 0;

	private:

	};

}

#endif
