
#include <fstream>
#include "in_out/in_out.h"
#include "generator/Generator.h"
#include "algorithm/Algorithms.h"

void computeConnectedComponents(Graph* graph) {
    DFS(graph);
}

void computeDiameterGraph(Graph* graph) {

    for (unsigned i = 0; i < graph->getConnectedComponentsCount(); ++i) {
        unsigned diameter = 0;
        ConnectedComponent* analyzed = graph->getConnectedComponentsVector(i);
        for (unsigned j = 0; j < graph->getConnectedComponentsSize(i); ++j) {
            unsigned candidate = BFS(analyzed, analyzed->getVertex(j));
            if (candidate > diameter)
                diameter = candidate;
        }
    }
}

int main() {

    srand(time(NULL));
    Generator* generator = new Generator();
    generator->generateAll();

    unsigned files = 2* generator->getGraphsCount()/generator->getGraphsOnStep();
    unsigned graphsInFile = generator->getGraphsOnStep()/2;
    std::vector<std::string> inputFilesNames = generator->getFileNames();
    std::fstream inputFile;
    std::string temp;

    for(int i = 0 ; i < files; ++i){
        inputFile.open(inputFilesNames[i], std::ios::in | std::ios::out);
        if(!inputFile.is_open())
            std::cerr<< "Error in opening file " << inputFilesNames[i] << std::endl;
        for (int j = 0; j < graphsInFile; ++j){
            Graph* graph = new Graph();
            read_data(graph, inputFile);

        }
        inputFile.close();
    }

//    std::cout<< graph->toString();

//
//    computeConnectedComponents(graph);
//    computeDiameterGraph(graph);

    return 0;
}