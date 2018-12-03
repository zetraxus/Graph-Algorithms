//
// Created by Adam on 03.12.18.
//

#ifndef AAL_GRAPH_H
#define AAL_GRAPH_H

#include <vector>

class Graph {

    unsigned vertex;
    unsigned edge;
    std::vector<std::vector<int> > edgesList;

public:
    Graph();
    Graph(unsigned vertex, unsigned edge, std::vector<std::vector<int> > edgesList);
    void addEdge(unsigned v1, unsigned v2);
};


#endif //AAL_GRAPH_H
