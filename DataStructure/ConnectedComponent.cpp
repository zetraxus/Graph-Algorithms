//
// Created by adam on 08.12.18.
//

#include <iostream>
#include "ConnectedComponent.h"

void ConnectedComponent::add(Vertex* vertex) {
    vertices.push_back(vertex);
}

Vertex* ConnectedComponent::getVertex(unsigned index) const {
    return vertices[index];
}

unsigned ConnectedComponent::getSize() const {
    return vertices.size();
}

const std::vector<Vertex*>& ConnectedComponent::getVertices() const {
    return vertices;
}
