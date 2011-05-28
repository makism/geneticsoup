#ifndef _GENETICSOUP_HELPERS_HPP_
#define _GENETICSOUP_HELPERS_HPP_


#ifdef unix
#   include <fstream>
#else
#   include <ctime>
#endif

namespace GeneticSoup {
    namespace Helpers {

        // Based on
        // http://www.mitchr.me/SS/exampleCode/boost/boostRandEx.cpp.html
        // and http://sci.tuomastonteri.fi/programming/cplus/wrapper-to-boost-random
        // !!! needs optimization !!!
        class Random {
        public:
            ~Random(void) {
                delete uniDblGen;
                delete uniDblUnit;
                delete baseGen;
            }
            
            static Random* Instance(void) {
                if (mInstance==0)
                    mInstance = new Random();
                
                return mInstance;
            }
            
            double Generate(void) const {
                return (*uniDblGen)();
            }
            
            int Generate(int start, int end) const {
                boost::uniform_int<> uniInt(start, end);
                
                boost::variate_generator<boost::minstd_rand&, boost::uniform_int<> > uniIntGen(*baseGen, uniInt);
                
                return uniIntGen.operator()();
            }
            
        private:
            Random(void) {
                baseGen = new boost::minstd_rand(static_cast<unsigned int>(Seed()));
                uniDblUnit = new boost::uniform_real<>(0, 1);
                uniDblGen = new boost::variate_generator<boost::minstd_rand&, boost::uniform_real<> >(*baseGen, *uniDblUnit);
            }
            
 #ifdef unix
            uint64_t Seed() const
            {
                uint64_t seed;
                std::ifstream urandom;
                urandom.open("/dev/urandom");
                urandom.read(reinterpret_cast<char*> (&seed), sizeof (seed));
                urandom.close();
                
                return seed;
            }
 #else
            uint64_t Seed() const;
            {
                return time(NULL);
            }
 #endif
            
            
        private:
            static Random* mInstance;
                
            boost::minstd_rand * baseGen;
            boost::uniform_real<> * uniDblUnit;
            boost::variate_generator<boost::minstd_rand&, boost::uniform_real<> > * uniDblGen;
        };
        
        Random* Random::mInstance = 0;
    }
}


#endif
 