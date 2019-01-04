//
// Created by adam on 07.12.18.
//

#ifndef AAL_ALGORITHMS_H
#define AAL_ALGORITHMS_H


#include "../DataStructure/Graph.h"
#include "../DataStructure/Clique.h"

typedef std::pair<unsigned, std::pair<unsigned, unsigned> > edgeDef;


void DFS(Graph* graph);

void DFSVisit(Graph* graph, Vertex* vertex, const unsigned connectedComponents);

unsigned BFS(ConnectedComponent* connectedComponent, Vertex* start);

const std::vector<std::vector<unsigned> > getAllSubsets(unsigned setSize);

unsigned computeNextCliques(std::vector<Clique*>& cliques, const std::vector<Vertex*>& vertices, unsigned startId);

std::vector<edgeDef> getEdges(ConnectedComponent* connectedComponent);

void MakeSet(std::vector<unsigned>& ancestors, std::vector<unsigned>& rank, const ConnectedComponent* connectedComponent);

void Union(unsigned xId, unsigned yId, std::vector<unsigned>& ancestors, std::vector<unsigned>& rank);

void Link(unsigned xId, unsigned yId, std::vector<unsigned>& ancestors, std::vector<unsigned>& rank);

unsigned FindSet(unsigned xId, std::vector<unsigned>& ancestors);

std::vector<edgeDef> MST(const ConnectedComponent* connectedComponent, unsigned graphSize);

#endif //AAL_ALGORITHMS_H