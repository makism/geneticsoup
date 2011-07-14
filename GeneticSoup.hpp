#ifndef _GENETICSOUP_HPP_
#define _GENETICSOUP_HPP_

#include <iostream>
#include <sstream>
#include <typeinfo>
#include <limits>
#include <string>
#include <iterator>
#include <vector>

#include <boost/type_traits.hpp>
#include "boost/random.hpp" 

#include "GeneticSoup_Version.hpp"
#include "GeneticSoup_Helpers.hpp"
#include "Headers/Parent.hpp"
#include "Headers/Pool.hpp"
#include "Headers/Population.hpp"
#include "Headers/Mutation.hpp"
#include "Headers/Genome.hpp"
#include "Headers/BinaryGenome.hpp"
// #include "Headers/NaturalNumberGenome.hpp"
#include "Headers/Crossover.hpp"
#include "Headers/Selection.hpp"
#include "Headers/Island.hpp"
#include "Headers/Topology.hpp"
#include "Headers/ConnectedIslands.hpp"

#include "Impl/PoolImpl.hpp"
#include "Impl/PopulationImpl.hpp"
#include "Impl/MutationImpl.hpp"
#include "Impl/GenomeImpl.hpp"
#include "Impl/BinaryGenomeImpl.hpp"
// #include "Impl/NaturalNumberGenomeImpl.hpp"
#include "Impl/CrossoverImpl.hpp"
#include "Impl/SelectionImpl.hpp"
#include "Impl/IslandImpl.hpp"
#include "Impl/TopologyImpl.hpp"
#include "Impl/ConnectedIslandsImpl.hpp"

#endif
