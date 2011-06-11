#ifndef _GENETICSOUP_HELPERS_REMOVEPOINTER_HPP_
#define _GENETICSOUP_HELPERS_REMOVEPOINTER_HPP_

namespace GeneticSoup {
    namespace Helpers {

template<typename T>
struct remove_pointer
{
typedef T type;
};

template<typename T>
struct remove_pointer<T*>
{
    typedef T type;
};

    }
}

#endif
