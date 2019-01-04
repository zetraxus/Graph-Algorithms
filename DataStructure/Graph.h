//
// Created by Adam on 03.12.18.
//

#ifndef AAL_GRAPH_H
#define AAL_GRAPH_H

#include <vector>
#include <iostream>
#include "Vertex.h"
#include "ConnectedComponent.h"
#include "GraphStatisticsTimes.h"

const unsigned MAXEDGEVALUE = 100;

class Graph {

    unsigned verticesCount;
    unsigned edgesCount;

    std::vector<Vertex*> vertices;
    std::vector<ConnectedComponent*> connectedComponentsVector;

    GraphStatisticsTimes time;

public:

    Graph();

    Graph(unsigned int verticesCount);

    ~Graph();

    void addEdge(unsigned v1, unsigned v2, unsigned value);

    void setVerticesCount(unsigned int verticesCount);

    unsigned getVerticesCount() const;

    Vertex* getVertex(int index) const;

    void setConnectedComponentsCount(unsigned connectedComponents);

    void addToConnectedComponentList(Vertex* vertex, unsigned connectedComponentID);

    unsigned long getConnectedComponentsCount() const;

    unsigned getConnectedComponentsSize(unsigned index) const;

    ConnectedComponent* getConnectedComponentsVector(unsigned index) const;

    GraphStatisticsTimes& getTime();

    std::string toString();
};


#endif //AAL_GRAPH_H
