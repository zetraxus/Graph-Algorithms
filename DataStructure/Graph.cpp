//
// Created by adam on 03.12.18.
//

#include "Graph.h"
#include "../Messages/Messages.h"

Graph::Graph() {
    verticesCount = 0;
    edgesCount = 0;
}

Graph::Graph(unsigned int verticesCount) : verticesCount(verticesCount) {
    edgesCount = 0;
    vertices.resize(verticesCount);

    for (unsigned i = 0; i < verticesCount; ++i) {
        vertices[i] = new Vertex(i);
    }
}

Graph::~Graph() {
    for (auto& i : vertices)
        delete i;
    for (auto& i : connectedComponentsVector)
        delete i;

    verticesCount = 0;
    edgesCount = 0;
}

void Graph::setVerticesCount(unsigned verticesCount) {
    this->verticesCount = verticesCount;
    vertices.resize(verticesCount);

    for (unsigned i = 0; i < verticesCount; ++i) {
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

Vertex* Graph::getVertex(int index) const {
    return vertices[index];
}

void Graph::setConnectedComponentsCount(unsigned connectedComponentsCount) {
    connectedComponentsVector.resize(connectedComponentsCount);
    for (unsigned i = 0; i < connectedComponentsCount; ++i)
        connectedComponentsVector[i] = new ConnectedComponent();
}

void Graph::addToConnectedComponentList(Vertex* vertex, unsigned connectedComponentID) {
    connectedComponentsVector[connectedComponentID]->add(vertex);
}

unsigned long Graph::getConnectedComponentsCount() const {
    return connectedComponentsVector.size();
}

unsigned Graph::getConnectedComponentsSize(unsigned index) const {
    return connectedComponentsVector[index]->getSize();
}

ConnectedComponent* Graph::getConnectedComponentsVector(unsigned index) const {
    return connectedComponentsVector[index];
}

unsigned int Graph::getEdgesCount() const {
    return edgesCount;
}

std::string Graph::toString() {
    std::string result = std::to_string(verticesCount) + SPACE + std::to_string(edgesCount) + NEWLINE;

    for (unsigned i = 0; i < verticesCount; ++i) {
        const std::vector<vuPair>& neighbour = vertices[i]->getConnectedVertices();
        for (unsigned j = 0; j < neighbour.size(); ++j) {
            if (neighbour[j].first->getId() > i) {
                result += std::to_string(i) + SPACE + std::to_string(neighbour[j].first->getId()) + SPACE +
                          std::to_string(neighbour[j].second) + NEWLINE;
            }
        }
    }

    return result;
}

GraphStatisticsTimes& Graph::getTime() {
    return time;
}
