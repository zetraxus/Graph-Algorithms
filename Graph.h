//
// Created by Adam on 03.12.18.
//

#ifndef AAL_GRAPH_H
#define AAL_GRAPH_H

#include <vector>

typedef std::pair<unsigned, unsigned > uuPair;

class Graph {

    unsigned verticesCount;
    unsigned edgesCount;
    std::vector<std::vector<uuPair> > edgesList;

public:
    void setVerticesCount(unsigned int verticesCount);
    void setEdgesCount(unsigned int edgesCount);

public:
    Graph();

    void addEdge(unsigned v1, unsigned v2, unsigned value);
};


#endif //AAL_GRAPH_H
