//
// Created by adam on 07.12.18.
//

#ifndef AAL_ALGORITHMS_H
#define AAL_ALGORITHMS_H

#include "../data_structure/Graph.h"

void DFS(Graph* graph);

void DFSVisit(Graph* graph, Vertex* vertex, const unsigned connectedComponents);

unsigned BFS(ConnectedComponent* connectedComponent, Vertex* start);

const std::vector<std::vector<unsigned> > getAllSubsets(unsigned setSize);

#endif //AAL_ALGORITHMS_H