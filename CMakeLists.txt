cmake_minimum_required(VERSION 3.12)
project(AAL)

set(CMAKE_CXX_STANDARD 11)

add_executable(AAL main.cpp in_out.cpp in_out.h Graph.cpp Algorithms.cpp Algorithms.h Vertex.cpp Vertex.h ConnectedComponent.cpp ConnectedComponent.h)
