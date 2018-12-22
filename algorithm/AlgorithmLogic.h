//
// Created by adam on 19.12.18.
//

#ifndef AAL_TESTED_H
#define AAL_TESTED_H


#include "../data_structure/Graph.h"

void computeConnectedComponents(Graph* graph);

unsigned computeDiameterGraph(Graph* graph);

std::vector< std::vector<unsigned> > computeCliquesBruteForce(const Graph* graph);

void MSTonConnectedComponents(Graph* graph);

void MSTonGraph(Graph* graph);

#endif //AAL_TESTED_H
