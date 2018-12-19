//
// Created by adam on 19.12.18.
//

#include <iostream>
#include "AlgorithmLogic.h"
#include "Implementation.h"

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

void computeCliques(const Graph* graph){
//    const std::vector< std::vector<unsigned> > subsets = getAllSubsets(graph->getVerticesCount());
//    for (unsigned i = 0 ; i < subsets.size(); ++i){
//        for (unsigned j = 0 ; j < subsets[i].size(); ++j){
//            std::cout<<subsets[i][j] << " ";
//        }
//        std::cout<<std::endl;
//    }
    //check all subsets
}