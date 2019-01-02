//
// Created by adam on 19.12.18.
//

#ifndef AAL_TESTED_H
#define AAL_TESTED_H


#include "../data_structure/Graph.h"
#include "Implementation.h"
#include "../data_structure/MSTgraph.h"
#include "../data_structure/Clique.h"

class AlgorithmLogic {

public:

    void computeConnectedComponents(Graph* graph); // return value: execution time

    unsigned computeDiameterGraph(Graph* graph); // return value: diameter & average execution time

    std::vector<std::vector<unsigned> > computeCliquesBruteForce(Graph* graph); // return value: cliques & execution time

    std::vector<Clique*> computeCliquesHeuristic(Graph* graph); // return value: cliques & execution time

    MSTgraph* MSTonConnectedComponents(Graph* graph); // return value: MST & execution time

    MSTgraph* MSTonGraph(MSTgraph* mstGraph, Graph*& graph); // return value: MST & execution time
};


#endif //AAL_TESTED_H
