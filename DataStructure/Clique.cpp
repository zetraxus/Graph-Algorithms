//
// Created by adam on 23.12.18.
//

#include "Clique.h"

Clique::Clique(Vertex* vertex) {
    vertices.push_back(vertex);
    minimumVertexDegree = vertex->getDegree();
}
