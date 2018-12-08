//
// Created by adam on 08.12.18.
//

#include "ConnectedComponent.h"

void ConnectedComponent::add(Vertex *vertex) {
    vertices.push_back(vertex);
}

Vertex* ConnectedComponent::getVertex(unsigned index) {
    return vertices[index];
}

unsigned ConnectedComponent::getSize(){
    return vertices.size();
}
