//
// Created by adam on 17.12.18.
//

#ifndef AAL_GENERATOR_H
#define AAL_GENERATOR_H


#include "Graph.h"

class Generator {
    unsigned graphsCount;
    Graph **graphs;

public:

    Generator(unsigned int graphsCount);

    Graph *generateGraph();

    void generateAll();

    Graph **getGraphs();

};


#endif //AAL_GENERATOR_H
