cmake_minimum_required(VERSION 3.12)
project(AAL)

set(CMAKE_CXX_STANDARD 11)

add_executable(AAL main.cpp InOut/InOut.cpp InOut/InOut.h DataStructure/Graph.cpp Algorithm/Implementation.cpp Algorithm/Implementation.h DataStructure/Vertex.cpp DataStructure/Vertex.h DataStructure/ConnectedComponent.cpp DataStructure/ConnectedComponent.h Generator/Generator.cpp Generator/Generator.h Messages/Messages.h Algorithm/AlgorithmLogic.cpp Algorithm/AlgorithmLogic.h DataStructure/MSTgraph.cpp DataStructure/MSTgraph.h ProgramLogic/ProgramLogic.cpp ProgramLogic/ProgramLogic.h DataStructure/GraphStatisticsTimes.cpp DataStructure/GraphStatisticsTimes.h)
