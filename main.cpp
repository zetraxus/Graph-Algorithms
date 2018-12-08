#include <iostream>
#include "in_out.h"
#include "Graph.h"
#include "Algorithms.h"

void computeConnectedComponents(Graph* graph){
    DFS(graph);
}

void computeDiameterGraph(Graph* graph){

    for(unsigned i = 0 ; i < graph->getConnectedComponentsCount(); ++i){
        unsigned diameter = 0;
        ConnectedComponent* analyzed = graph-> getConnectedComponentsVector(i);
        for (unsigned j = 0; j < graph-> getConnectedComponentsSize(i); ++j){
            unsigned candidate = BFS(analyzed, analyzed->getVertex(j));
            if (candidate > diameter)
                diameter = candidate;
        }
    }
}

int main() {

    Graph* graph = new Graph();
    read_data(graph);

    computeConnectedComponents(graph);
    computeDiameterGraph(graph);

    return 0;
}