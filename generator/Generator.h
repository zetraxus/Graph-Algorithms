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
const std::string DIRECTORY = "input_files";

const bool DENSE = true;
const bool SPARSE = false;

class Generator {
    unsigned graphsCount;
    unsigned minimumVerticesCount;
    unsigned stepSize;
    unsigned graphsOnStep;
    std::string directory;

    std::vector<std::string> inputFileNames;
    std::vector<std::string> outputFileNames;

public:

    Generator(unsigned graphs = GRAPHCOUNT, unsigned minimumVertices = MINIMUMVERTICESCOUNT,
              unsigned step = GRAPHSTEPSIZE, unsigned graphsOnStep = GRAPHSONSTEP, std::string directory = DIRECTORY);

    Graph* generateGraph(bool isDense, unsigned verticesCount);

    void generateAll();

    unsigned int getGraphsCount() const;

    unsigned int getMinimumVerticesCount() const;

    unsigned int getStepSize() const;

    unsigned int getGraphsOnStep() const;

    const std::string& getDirectory() const;

    const std::vector<std::string>& getInputFileNames() const;

    const std::vector<std::string>& getOutputFileNames() const;
};


#endif //AAL_GENERATOR_H
