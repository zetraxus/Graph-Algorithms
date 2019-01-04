//
// Created by adam on 19.12.18.
//

#ifndef AAL_TESTED_H
#define AAL_TESTED_H

#include "Implementation.h"
#include "../DataStructure/Graph.h"
#include "../DataStructure/Clique.h"
#include "../DataStructure/MSTgraph.h"

class AlgorithmLogic {

public:

    void computeConnectedComponents(Graph* graph);

    unsigned computeDiameterGraph(Graph* graph);

    std::vector<std::vector<unsigned> > computeCliquesBruteForce(Graph* graph);

    std::vector<Clique*> computeCliquesHeuristic(Graph* graph);

    MSTgraph* MSTonConnectedComponentsKruskal(Graph* graph);

    MSTgraph* MSTonConnectedComponentsPrim(Graph* graph);

    MSTgraph* MSTonGraph(MSTgraph* mstGraph, Graph*& graph);
};


#endif //AAL_TESTED_H
