//
// Created by adam on 17.12.18.
//

#ifndef AAL_GENERATOR_H
#define AAL_GENERATOR_H


#include "Graph.h"

const unsigned GRAPHCOUNT = 200;
const unsigned MINIMUMVERTICESCOUNT = 10;
const unsigned GRAPHSONSTEP = 100;
const unsigned GRAPHSTEPSIZE = 10;

const bool DENSE = true;
const bool SPARSE = false;

class Generator {
    unsigned graphsCount;
    unsigned minimumVerticesCount;
    unsigned stepSize;
    unsigned graphsOnStep;
    Graph** graphs;

public:

    Generator(unsigned graphs = GRAPHCOUNT, unsigned minimumVertices = MINIMUMVERTICESCOUNT,
              unsigned step = GRAPHSTEPSIZE, unsigned graphsOnStep = GRAPHSONSTEP);

    Graph* generateGraph(bool isDense, unsigned verticesCount);

    void generateAll();

    Graph** getGraphs();

};


#endif //AAL_GENERATOR_H
