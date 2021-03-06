//
// Created by adam on 07.12.18.
//

#include "Vertex.h"

Vertex::Vertex(unsigned id) : id(id) {}

void Vertex::addEdge(Vertex* vertex, unsigned value) {
    vuPair edge = std::make_pair(vertex, value);
    connectedVertex.push_back(edge);
}

unsigned Vertex::getDegree() {
    return connectedVertex.size();
}

Vertex::Colour Vertex::getColour() const {
    return colour;
}

void Vertex::setColour(Vertex::Colour colour) {
    Vertex::colour = colour;
}

void Vertex::setConnectedComponentID(unsigned int connectedComponentID) {
    Vertex::connectedComponentID = connectedComponentID;
}

Vertex* Vertex::getNeighbour(unsigned index) {
    return connectedVertex[index].first;
}

unsigned int Vertex::getConnectedComponentID() const {
    return connectedComponentID;
}

unsigned Vertex::getId() const {
    return id;
}

unsigned int Vertex::getDistance() const {
    return distance;
}

void Vertex::setDistance(unsigned int distance) {
    Vertex::distance = distance;
}

const std::vector<vuPair>& Vertex::getConnectedVertices() const {
    return connectedVertex;
}

bool Vertex::isNeighbour(Vertex* other) const {
    for (unsigned i = 0; i < connectedVertex.size(); ++i) {
        if (connectedVertex[i].first == other)
            return true;
    }

    return false;
}
