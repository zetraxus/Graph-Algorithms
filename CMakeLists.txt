cmake_minimum_required(VERSION 3.12)
project(AAL)

set(CMAKE_CXX_STANDARD 11)

add_executable(AAL main.cpp in_out/in_out.cpp in_out/in_out.h data_structure/Graph.cpp algorithm/Implementation.cpp algorithm/Implementation.h data_structure/Vertex.cpp data_structure/Vertex.h data_structure/ConnectedComponent.cpp data_structure/ConnectedComponent.h generator/Generator.cpp generator/Generator.h messages/Messages.h algorithm/AlgorithmLogic.cpp algorithm/AlgorithmLogic.h data_structure/MSTgraph.cpp data_structure/MSTgraph.h data_structure/Clique.cpp data_structure/Clique.h)
