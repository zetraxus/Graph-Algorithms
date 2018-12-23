//
// Created by adam on 19.12.18.
//

#include <iostream>
#include "AlgorithmLogic.h"
#include "Implementation.h"
#include "../data_structure/MSTgraph.h"

void computeConnectedComponents(Graph* graph) {
    DFS(graph);
}

unsigned computeDiameterGraph(Graph* graph) {
    unsigned diameter = 0;
    for (unsigned i = 0; i < graph->getConnectedComponentsCount(); ++i) {
//        unsigned diameter = 0;
        ConnectedComponent* analysed = graph->getConnectedComponentsVector(i);
        for (unsigned j = 0; j < graph->getConnectedComponentsSize(i); ++j) {
            unsigned candidate = BFS(analysed, analysed->getVertex(j));
            if (candidate > diameter)
                diameter = candidate;
        }
    }
    return diameter;
}

std::vector<std::vector<unsigned> > computeCliquesBruteForce(const Graph* graph) {
    const std::vector<std::vector<unsigned> > subsets = getAllSubsets(graph->getVerticesCount());
    std::vector<std::vector<unsigned> > cliques;

    bool isClique;
    for (int i = 0; i < subsets.size(); ++i) {
        isClique = true;
        for (int j = 0; j < subsets[i].size(); ++j) {
            for (int k = j + 1; k < subsets[i].size(); ++k) {
                if (!graph->getVertex(subsets[i][j])->isNeighbour(graph->getVertex(subsets[i][k]))) {
                    isClique = false;
                    break;
                }
            }
            if (!isClique)
                break;
        }

        if (isClique)
            cliques.push_back(subsets[i]);
    }

    return cliques;
}

MSTgraph* MSTonConnectedComponents(Graph* graph){
    MSTgraph* mstGraph = new MSTgraph();

    std::vector<std::vector<edgeDef> > results;
    for(unsigned i = 0 ; i < graph->getConnectedComponentsCount(); ++i){
        if(graph->getConnectedComponentsSize(i) == 1)
            mstGraph->addToIsolatedVertices(graph->getConnectedComponentsVector(i)->getVertex(0)->getId());
        else
            mstGraph->addVectorToMSTonCC(MST(graph->getConnectedComponentsVector(i), graph->getVerticesCount()));
    }

    return mstGraph;
}

MSTgraph* MSTonGraph(MSTgraph* mstGraph){
    mstGraph->computeMSTonGraph();
    return mstGraph;
}