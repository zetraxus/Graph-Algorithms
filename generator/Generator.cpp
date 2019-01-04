//
// Created by adam on 17.12.18.
//

#include "Generator.h"
#include <fstream>


Graph* Generator::generateGraph(bool isDense, unsigned verticesCount) {
    unsigned maxEdges = verticesCount * (verticesCount - 1) / 2;
    unsigned edges = rand() % (maxEdges / 4);

    if (isDense == true)
        edges += maxEdges * 3 / 4;
    Graph* newGraph = new Graph(verticesCount);

    std::vector<std::pair<unsigned, unsigned> > temp;
    for (unsigned i = 0; i < verticesCount; ++i) {
        for (unsigned j = i + 1; j < verticesCount; ++j) {
            temp.push_back(std::make_pair(i, j));
        }
    }

    for (int i = 0; i < edges; ++i) {
        unsigned newEdgeIndex = rand() % (edges - i);
        unsigned value = (rand() % MAXEDGEVALUE) + 1;

        newGraph->addEdge(temp[newEdgeIndex].first, temp[newEdgeIndex].second, value);
        temp[newEdgeIndex] = temp[maxEdges - i - 1];
    }

    return newGraph;
}

void Generator::generateAll() {
    unsigned vertices = minimumVerticesCount;

    Graph* generated;
    std::string inputFileName;
    std::string outputFileName;
    std::ofstream inputFile;

    for (int i = 0; i < graphsCount; ++i) {
        if (i % graphsOnStep == 0 && i != 0)
            vertices += stepSize;

        if (i % (graphsOnStep / 2) == 0) {
            if (inputFile.is_open()) {
                inputFile.close();
            }

            if (i % graphsOnStep == 0) {
                inputFileName = directory + INPUT + std::to_string(vertices) + FNEXTENSTIONDENSE;
                outputFileName = directory + OUTPUT + std::to_string(vertices) + FNEXTENSTIONDENSE;
            } else {
                inputFileName = directory + INPUT + std::to_string(vertices) + FNEXTENSTIONSPARSE;
                outputFileName = directory + OUTPUT + std::to_string(vertices) + FNEXTENSTIONSPARSE;
            }

            std::cout << inputFileName << std::endl;
            std::cout << outputFileName << std::endl;

            inputFileNames.push_back(inputFileName);
            outputFileNames.push_back(outputFileName);

            std::string tescik = inputFileName;
            inputFile.open(tescik);

            if (!inputFile.is_open()) {
                std::cerr << "test " << ERROROPENFILE << inputFileName << std::endl;
            }
        }
        if (i % graphsOnStep < graphsOnStep / 2)
            generated = generateGraph(DENSE, vertices);
        else
            generated = generateGraph(SPARSE, vertices);

        inputFile << generated->toString() + NEWLINE;
    }

    inputFile.close();
}

Generator::Generator(unsigned graphs, unsigned minimumVertices, unsigned step, unsigned graphsOnStep,
                     std::string directoryName) : graphsCount(
        graphs), minimumVerticesCount(minimumVertices), stepSize(step), graphsOnStep(graphsOnStep),
                                                  directory(directoryName) {}

unsigned int Generator::getGraphsCount() const {
    return graphsCount;
}

unsigned int Generator::getGraphsOnStep() const {
    return graphsOnStep;
}

const std::vector<std::string>& Generator::getInputFileNames() const {
    return inputFileNames;
}

const std::vector<std::string>& Generator::getOutputFileNames() const {
    return outputFileNames;
}
