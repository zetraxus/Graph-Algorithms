//
// Created by adam on 03.12.18.
//

#include "Graph.h"

Graph::Graph(){
    verticesCount = 0;
    edgesCount = 0;
}

void Graph::setVerticesCount(unsigned int verticesCount) {
    this->verticesCount = verticesCount;
    edgesList.resize(verticesCount);
}

void Graph::setEdgesCount(unsigned int edgesCount) {
    this->edgesCount = edgesCount;
}

void Graph::addEdge(unsigned v1, unsigned v2, unsigned value) {
    uuPair pair1, pair2;    // undirected graph
    pair1 = std::make_pair(v1, value);
    pair1 = std::make_pair(v2, value);

    edgesList[v1].push_back(pair2);
    edgesList[v2].push_back(pair1);

    ++edgesCount;
}