//
// Created by adam on 17.12.18.
//

#ifndef AAL_GENERATOR_H
#define AAL_GENERATOR_H

#include "../Messages/Messages.h"
#include "../DataStructure/Graph.h"

const unsigned GRAPHCOUNT = 2000;
const unsigned MINIMUMVERTICESCOUNT = 100;
const unsigned GRAPHSONSTEP = 100;
const unsigned GRAPHSTEPSIZE = MINIMUMVERTICESCOUNT/2;

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
    std::vector<std::string> filesDescriptions;

    unsigned maxEdgesCount(unsigned verticesCount) const;

public:

    Generator(unsigned graphs = GRAPHCOUNT, unsigned minimumVertices = MINIMUMVERTICESCOUNT, unsigned step = GRAPHSTEPSIZE, unsigned graphsOnStep = GRAPHSONSTEP, std::string directory = DIRECTORYINPUTFILES);

    Graph* generateGraph(bool isDense, unsigned verticesCount);

    void generateAll();

    unsigned int getGraphsCount() const;

    unsigned int getGraphsOnStep() const;

    const std::vector<std::string>& getInputFileNames() const;

    const std::vector<std::string>& getOutputFileNames() const;

    const std::vector<std::string>& getFilesDescriptions() const;
};


#endif //AAL_GENERATOR_H
