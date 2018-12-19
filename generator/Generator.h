//
// Created by adam on 17.12.18.
//

#ifndef AAL_GENERATOR_H
#define AAL_GENERATOR_H


#include "../data_structure/Graph.h"

const unsigned GRAPHCOUNT = 200;
const unsigned MINIMUMVERTICESCOUNT = 10;
const unsigned GRAPHSONSTEP = 100;
const unsigned GRAPHSTEPSIZE = 5;

const bool DENSE = true;
const bool SPARSE = false;

class Generator {
    unsigned graphsCount;
    unsigned minimumVerticesCount;
    unsigned stepSize;
    unsigned graphsOnStep;
    std::vector<std::string> fileNames;

public:

    Generator(unsigned graphs = GRAPHCOUNT, unsigned minimumVertices = MINIMUMVERTICESCOUNT,
              unsigned step = GRAPHSTEPSIZE, unsigned graphsOnStep = GRAPHSONSTEP);

    Graph* generateGraph(bool isDense, unsigned verticesCount);

    void generateAll();

    unsigned int getGraphsCount() const;

    unsigned int getMinimumVerticesCount() const;

    unsigned int getStepSize() const;

    unsigned int getGraphsOnStep() const;

    const std::vector<std::string>& getFileNames() const;
};


#endif //AAL_GENERATOR_H
