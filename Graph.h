//
// Created by Adam on 03.12.18.
//

#ifndef AAL_GRAPH_H
#define AAL_GRAPH_H

#include <vector>
#include "Vertex.h"
//typedef std::pair<unsigned, unsigned > uuPair;

class Graph {

    unsigned verticesCount;
    unsigned edgesCount;
    unsigned connectedComponents = 0;

    std::vector<Vertex*> vertices;

public:

    Graph();

    void addEdge(unsigned v1, unsigned v2, unsigned value);

    void setVerticesCount(unsigned int verticesCount);

    unsigned int getVerticesCount() const;
};


#endif //AAL_GRAPH_H
