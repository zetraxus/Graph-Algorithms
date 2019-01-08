//
// Created by adam on 17.12.18.
//

#include "Generator.h"
#include "../DataStructure/Graph.h"
#include <fstream>
#include <sys/stat.h>

unsigned Generator::maxEdgesCount(unsigned verticesCount) const{
    return verticesCount * (verticesCount - 1) / 2;
}

Graph* Generator::generateGraph(bool isDense, unsigned verticesCount) {
    unsigned maxEdges = maxEdgesCount(verticesCount);
    unsigned edges;

    isDense ? edges = maxEdges * 3/4 : edges = maxEdges / 4;

    Graph* newGraph = new Graph(verticesCount);

    std::vector<std::pair<unsigned, unsigned> > temp;
    for (unsigned i = 0; i < verticesCount; ++i) {
        for (unsigned j = i + 1; j < verticesCount; ++j) {
            temp.emplace_back(i, j);
        }
    }

    for (unsigned i = 0; i < edges; ++i) {
        unsigned newEdgeIndex = rand() % (edges - i);
        unsigned value = (rand() % MAXEDGEVALUE) + 1;

        newGraph->addEdge(temp[newEdgeIndex].first, temp[newEdgeIndex].second, value);
        temp[newEdgeIndex] = temp[maxEdges - i - 1];
    }

    return newGraph;
}

void Generator::generateAll() {
    if(mkdir(DIRECTORYINPUTFILES.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)){
        std::cout << ERRORCREATEDIRECTORY + DIRECTORYINPUTFILES << NEWLINE;
        exit(0);
    }

    unsigned vertices = minimumVerticesCount;

    Graph* generated;
    std::string inputFileName;
    std::string outputFileName;
    std::string fileDescription;
    std::ofstream inputFile;

    for (unsigned i = 0; i < graphsCount; ++i) {
        if (i % graphsOnStep == 0 && i != 0)
            vertices += stepSize;

        if (i % (graphsOnStep / 2) == 0) {
            if (inputFile.is_open()) {
                inputFile.close();
            }

            if (i % graphsOnStep == 0) {
                inputFileName = directory + INPUT + std::to_string(vertices) + FNEXTENSTIONDENSE;
                outputFileName = directory + OUTPUT + std::to_string(vertices) + FNEXTENSTIONDENSE;
                fileDescription = VERTICES + "= " + std::to_string(vertices) + SPACE + EDGES + "= " + std::to_string(3 * maxEdgesCount(vertices)/4);
            } else {
                inputFileName = directory + INPUT + std::to_string(vertices) + FNEXTENSTIONSPARSE;
                outputFileName = directory + OUTPUT + std::to_string(vertices) + FNEXTENSTIONSPARSE;
                fileDescription = VERTICES + "= " + std::to_string(vertices) + SPACE + EDGES + "= " + std::to_string(maxEdgesCount(vertices)/4);
            }

            inputFileNames.push_back(inputFileName);
            outputFileNames.push_back(outputFileName);
            filesDescriptions.push_back(fileDescription);

            inputFile.open(inputFileName);

            if (!inputFile.is_open()) {
                std::cerr << ERROROPENFILE << inputFileName << std::endl;
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

const std::vector<std::string>& Generator::getFilesDescriptions() const {
    return filesDescriptions;
}

Generator::Generator(unsigned graphs, unsigned minimumVertices, unsigned step, unsigned graphsOnStep, std::string directoryName) : graphsCount(graphs), minimumVerticesCount(minimumVertices), stepSize(step), graphsOnStep(graphsOnStep), directory(std::move(std::move(directoryName))) {}

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
