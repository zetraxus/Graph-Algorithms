//
// Created by adam on 19.12.18.
//

#ifndef AAL_TESTED_H
#define AAL_TESTED_H


#include "../data_structure/Graph.h"
#include "Implementation.h"

void computeConnectedComponents(Graph* graph);

unsigned computeDiameterGraph(Graph* graph);

std::vector< std::vector<unsigned> > computeCliquesBruteForce(const Graph* graph);

std::vector<std::vector<edgeDef> >  MSTonConnectedComponents(Graph* graph);

std::vector<std::vector<edgeDef> > MSTonGraph(Graph* graph);

#endif //AAL_TESTED_H
