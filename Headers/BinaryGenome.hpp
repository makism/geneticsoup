 #ifndef _BINARYGENOME_HPP_
 #define _BINARYGENOME_HPP_
 
 namespace GeneticSoup
 {
     
     class BinaryGenome: public Genome<short>
     {
     public:
         BinaryGenome(void);
         BinaryGenome(unsigned int);
         virtual ~BinaryGenome(void);
         
     protected:
         void Generate(void);
     };
     
 }
 
 #endif
 
 


