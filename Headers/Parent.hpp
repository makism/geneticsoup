#ifndef _PARENT_HPP_
#define _PARENT_HPP_

namespace GeneticSoup {
	
	class Parent {
	
	public:
		template<class U>
		friend class Population;
	
	protected:
		void* mParent;
		
	};
	
}

#endif
