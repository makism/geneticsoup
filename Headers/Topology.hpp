#ifndef _TOPOLOGY_HPP_
#define _TOPOLOGY_HPP_


namespace GeneticSoup {

template<class T>
class Topology {
 
public:
    Topology(std::vector< Island<T> *> islands);
    virtual ~Topology(void);
    
private:
    std::vector< Island<T> *> islands;
};

template<class T>
class Line: public Topology<T> {

};

template<class T>
class Grid: public Topology<T> {

};

template<class T>
class Grid3D: public Topology<T> {

};

template<class T>
class FullMesh: public Topology<T> {

};

template<class T>
class RandomMesh: public Topology<T> {

};

}

#endif
