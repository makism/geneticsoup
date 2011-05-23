cmake_minimum_required (VERSION 2.6) 
project (geneticsoup_examples)
set(CMAKE_BUILD_TYPE "Debug")

find_package(Boost)
 
include_directories (${geneticsoup_examples_SOURCE_DIR}/../
						${geneticsoup_examples_SOURCE_DIR}/../Headers
						${geneticsoup_examples_SOURCE_DIR}/../Impl)
 
add_executable (ExamplePool Pool.cpp)
add_executable (ExampleGenome Genome.cpp)
add_executable (ExamplePopulation Population.cpp)
add_executable (ExampleIsland Island.cpp)
add_executable (ExampleMutation Mutation.cpp)
