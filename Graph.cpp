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
    vertices.resize(verticesCount);
}

void Graph::addEdge(unsigned v1, unsigned v2, unsigned value) {
    Vertex* vertex1 = vertices[v1];
    Vertex* vertex2 = vertices[v2];

    vertex1->addEdge(vertex2, value);
    vertex2->addEdge(vertex1, value); //undirected graph

    ++edgesCount;
}

unsigned int Graph::getVerticesCount() const {
    return verticesCount;
}
