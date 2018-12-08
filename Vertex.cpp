//
// Created by adam on 07.12.18.
//

#include "Vertex.h"

Vertex::Vertex(unsigned int id) : id(id) {}

void Vertex::addEdge(Vertex* vertex, unsigned value) {
    vuPair edge = std::make_pair(vertex, value);
    connectedVertex.push_back(edge);
}
