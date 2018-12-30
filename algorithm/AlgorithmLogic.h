//
// Created by adam on 19.12.18.
//

#ifndef AAL_TESTED_H
#define AAL_TESTED_H


#include "../data_structure/Graph.h"
#include "Implementation.h"
#include "../data_structure/MSTgraph.h"
#include "../data_structure/Clique.h"

void computeConnectedComponents(Graph* graph);

unsigned computeDiameterGraph(Graph* graph);

std::vector<std::vector<unsigned> > computeCliquesBruteForce(const Graph* graph);

std::vector<Clique*> computeCliquesHeuristic(Graph* graph);

MSTgraph* MSTonConnectedComponents(Graph* graph);

MSTgraph* MSTonGraph(MSTgraph* mstGraph);

#endif //AAL_TESTED_H
