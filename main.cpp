#include <fstream>
#include "in_out/in_out.h"
#include "generator/Generator.h"
#include "algorithm/Implementation.h"
#include "algorithm/AlgorithmLogic.h"


int main() {

    srand(time(NULL));
    Generator* generator = new Generator();
    generator->generateAll();

    const unsigned files = 2 * generator->getGraphsCount() / generator->getGraphsOnStep();
    const unsigned graphsInFile = generator->getGraphsOnStep() / 2;
    const std::vector<std::string> inputFilesNames = generator->getInputFileNames();
    const std::vector<std::string> outputFilesNames = generator->getOutputFileNames();
    std::vector<std::vector<unsigned> > cliquesBrute;
    std::vector<std::vector<unsigned> > cliquesHeur;

    std::fstream inputFile;
    std::ofstream outputFile;
    unsigned diameter;

    for (unsigned i = 0; i < 2; ++i) {
        inputFile.open(inputFilesNames[i]);
        outputFile.open(outputFilesNames[i]);

        if (!inputFile.is_open())
            std::cerr << ERRORFILEOPEN << inputFilesNames[i] << std::endl;
        if (!outputFile.is_open()) {
            std::cerr << ERRORFILEOPEN << outputFilesNames[i] << std::endl;
        }

        for (unsigned j = 0; j < 5; ++j) {
            Graph* graph = new Graph();
            MSTgraph* mstGraph;
            read_data(graph, inputFile);

            std::cout << i << " " << j << std::endl;
            computeConnectedComponents(graph);
            diameter = computeDiameterGraph(graph);
//            cliquesBrute = computeCliquesBruteForce(graph);
            cliquesHeur = computeCliquesHeuristic(graph);
            mstGraph = MSTonConnectedComponents(graph);
            MSTonGraph(mstGraph);

            outputFile << GRAPHDESCRIPTION << j << ":" << NEWLINE;
            outputFile << DIAMETER << diameter << NEWLINE;
            outputFile << CONNECTEDCOMPONENTS << graph->getConnectedComponentsCount() << NEWLINE;
            outputFile << MSTONGRAPH << mstGraph->getMSTValue() << NEWLINE;
            outputFile << NEWLINE;

            delete graph;
        }
        inputFile.close();
        outputFile.close();
    }

    return 0;
}