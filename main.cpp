#include <fstream>
#include "in_out/in_out.h"
#include "generator/Generator.h"
#include "algorithm/Algorithms.h"

void computeConnectedComponents(Graph* graph) {
    DFS(graph);
}

unsigned computeDiameterGraph(Graph* graph) {
    unsigned diameter = 0;
    for (unsigned i = 0; i < graph->getConnectedComponentsCount(); ++i) {
//        unsigned diameter = 0;
        ConnectedComponent* analyzed = graph->getConnectedComponentsVector(i);
        for (unsigned j = 0; j < graph->getConnectedComponentsSize(i); ++j) {
            unsigned candidate = BFS(analyzed, analyzed->getVertex(j));
            if (candidate > diameter)
                diameter = candidate;
        }
    }
    return diameter;
}

int main() {

    srand(time(NULL));
    Generator* generator = new Generator();
    generator->generateAll();

    const unsigned files = 2 * generator->getGraphsCount() / generator->getGraphsOnStep();
    const unsigned graphsInFile = generator->getGraphsOnStep() / 2;
    const std::vector<std::string> inputFilesNames = generator->getInputFileNames();
    const std::vector<std::string> outputFilesNames = generator->getOutputFileNames();
    std::fstream inputFile;
    std::ofstream outputFile;
    unsigned diameter;

    for (int i = 0; i < files; ++i) {
        inputFile.open(inputFilesNames[i]);
        outputFile.open(outputFilesNames[i]);

        if (!inputFile.is_open())
            std::cerr << ERRORFILEOPEN << inputFilesNames[i] << std::endl;
        if (!outputFile.is_open()) {
            std::cerr << ERRORFILEOPEN << outputFilesNames[i] << std::endl;
        }
        for (int j = 0; j < graphsInFile; ++j) {
            Graph* graph = new Graph();
            read_data(graph, inputFile);

            computeConnectedComponents(graph);
            diameter = computeDiameterGraph(graph);

            outputFile << GRAPHDESCRIPTION << j << ":" << NEWLINE;
            outputFile << diameter << NEWLINE;
            outputFile << graph->getConnectedComponentsCount() << NEWLINE;

            delete graph;
        }
        inputFile.close();
        outputFile.close();
    }

    return 0;
}