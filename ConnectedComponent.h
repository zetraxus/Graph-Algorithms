//
// Created by adam on 08.12.18.
//

#ifndef AAL_CONNECTEDCOMPONENT_H
#define AAL_CONNECTEDCOMPONENT_H


#include "Vertex.h"

class ConnectedComponent {
    std::vector<Vertex*> vertices;

public:

    void add(Vertex* vertex);

    Vertex* getVertex(unsigned index);

    unsigned getSize();
};


#endif //AAL_CONNECTEDCOMPONENT_H
