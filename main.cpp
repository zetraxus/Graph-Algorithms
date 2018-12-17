
#include "in_out.h"
#include "Algorithms.h"
#include "Generator.h"

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
//        std::cout << std::endl << diameter;
    }
}

int main() {

    srand(time(NULL));
    Generator* generator = new Generator();

    generator->generateAll();
//    Graph** graphs = generator->getGraphs();
//    for (int i = 0 ; i < 20; ++i){
//        std::cout<< graphs[i]->getVerticesCount() << " - " << graphs[i]->getEdgesCount();
//    }
//    Graph* graph = new Graph();
//    read_data(graph);
//    std::cout<< graph->toString();

//
//    computeConnectedComponents(graph);
//    computeDiameterGraph(graph);

    return 0;
}