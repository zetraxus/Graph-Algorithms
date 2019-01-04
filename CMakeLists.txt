cmake_minimum_required(VERSION 3.12)
project(AAL)

set(CMAKE_CXX_STANDARD 11)

add_executable(AAL main.cpp InOut/InOut.cpp InOut/InOut.h DataStructure/Graph.cpp algorithm/Implementation.cpp algorithm/Implementation.h DataStructure/Vertex.cpp DataStructure/Vertex.h DataStructure/ConnectedComponent.cpp DataStructure/ConnectedComponent.h Generator/Generator.cpp Generator/Generator.h messages/Messages.h algorithm/AlgorithmLogic.cpp algorithm/AlgorithmLogic.h DataStructure/MSTgraph.cpp DataStructure/MSTgraph.h DataStructure/Clique.cpp DataStructure/Clique.h program_logic/ProgramLogic.cpp program_logic/ProgramLogic.h DataStructure/GraphStatisticsTimes.cpp DataStructure/GraphStatisticsTimes.h)
