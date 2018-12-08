//
// Created by Adam on 03.12.18.
//

#ifndef AAL_GRAPH_H
#define AAL_GRAPH_H

#include <vector>
#include <iostream>
#include "Vertex.h"

class Graph {

    unsigned verticesCount;
    unsigned edgesCount;
    unsigned connectedComponents = 0;

    std::vector<Vertex*> vertices;
    std::vector<std::vector<Vertex*> > connectedComponentsList;

public:

    Graph();

    void addEdge(unsigned v1, unsigned v2, unsigned value);

    void setVerticesCount(unsigned int verticesCount);

    unsigned getVerticesCount() const;

    Vertex* getVertex(int index);

    void setConnectedComponents(int connectedComponents);

    void addToConnectedComponentList(Vertex* vertex, unsigned connectedComponentID);

    unsigned getConnectedComponents() const;

    Vertex* getVertexFromConnectedComponentsList(unsigned connectedComponent, unsigned index);

    unsigned getConnectedComponentsSize(unsigned index) const;
};


#endif //AAL_GRAPH_H
