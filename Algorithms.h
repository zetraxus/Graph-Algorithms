//
// Created by adam on 07.12.18.
//

#ifndef AAL_ALGORITHMS_H
#define AAL_ALGORITHMS_H

#include "Graph.h"

void DFS(Graph *graph);

void DFSVisit(Graph *graph, Vertex *vertex, const unsigned connectedComponents);

unsigned BFS(Graph *graph, Vertex* start);

#endif //AAL_ALGORITHMS_H