#ifndef _TOPOLOGY_HPP_
#define _TOPOLOGY_HPP_


namespace GeneticSoup {

template<class T>
class Topology {

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
