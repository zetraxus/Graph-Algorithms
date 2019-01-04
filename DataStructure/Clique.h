//
// Created by adam on 23.12.18.
//

#ifndef AAL_CLIQUE_H
#define AAL_CLIQUE_H


#include "Vertex.h"

class Clique {
    std::vector<Vertex*> vertices;
    unsigned minimumVertexDegree;

public:
    Clique(Vertex* vertex);
};


#endif //AAL_CLIQUE_H
