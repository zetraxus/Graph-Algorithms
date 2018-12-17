//
// Created by adam on 03.12.18.
//

#include "Graph.h"

Graph::Graph() {
    verticesCount = 0;
    edgesCount = 0;
}

Graph::Graph(unsigned int verticesCount, unsigned int edgesCount) : verticesCount(verticesCount),
                                                                    edgesCount(edgesCount) {
    vertices.resize(verticesCount);

    for (int i = 0; i < verticesCount; ++i) {
        vertices[i] = new Vertex(i);
    }
}

void Graph::setVerticesCount(unsigned verticesCount) {
    this->verticesCount = verticesCount;
    vertices.resize(verticesCount);

    for (int i = 0; i < verticesCount; ++i) {
        vertices[i] = new Vertex(i);
    }
}

void Graph::addEdge(unsigned v1, unsigned v2, unsigned value) {
    Vertex *vertex1 = vertices[v1];
    Vertex *vertex2 = vertices[v2];

    vertex1->addEdge(vertex2, value);
    vertex2->addEdge(vertex1, value); //undirected graph

    ++edgesCount;
}

unsigned Graph::getVerticesCount() const {
    return verticesCount;
}

Vertex *Graph::getVertex(int index) {
    return vertices[index];
}

void Graph::setConnectedComponentsCount(unsigned connectedComponentsCount) {
    connectedComponentsVector.resize(connectedComponentsCount);
    for (int i = 0; i < connectedComponentsCount; ++i)
        connectedComponentsVector[i] = new ConnectedComponent();
}

void Graph::addToConnectedComponentList(Vertex *vertex, unsigned connectedComponentID) {
    connectedComponentsVector[connectedComponentID]->add(vertex);
}

unsigned long Graph::getConnectedComponentsCount() const {
    return connectedComponentsVector.size();
}

unsigned Graph::getConnectedComponentsSize(unsigned index) const {
    return connectedComponentsVector[index]->getSize();
}

ConnectedComponent *Graph::getConnectedComponentsVector(unsigned index) const {
    return connectedComponentsVector[index];
}
