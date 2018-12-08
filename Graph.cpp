//
// Created by adam on 03.12.18.
//

#include "Graph.h"
#include "Vertex.h"

Graph::Graph(){
    verticesCount = 0;
    edgesCount = 0;
}

void Graph::setVerticesCount(unsigned verticesCount) {
    this->verticesCount = verticesCount;
    vertices.resize(verticesCount);

    for (int i = 0; i < verticesCount; ++i){
        vertices[i] = new Vertex(i);
    }
}

void Graph::addEdge(unsigned v1, unsigned v2, unsigned value) {
    Vertex* vertex1 = vertices[v1];
    Vertex* vertex2 = vertices[v2];

    vertex1->addEdge(vertex2, value);
    vertex2->addEdge(vertex1, value); //undirected graph

    ++edgesCount;
}

unsigned Graph::getVerticesCount() const {
    return verticesCount;
}

Vertex* Graph::getVertex(int index){
    return vertices[index];
}
