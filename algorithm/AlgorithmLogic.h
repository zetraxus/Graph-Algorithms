//
// Created by adam on 19.12.18.
//

#ifndef AAL_TESTED_H
#define AAL_TESTED_H


#include "../data_structure/Graph.h"
#include "Implementation.h"
#include "../data_structure/MSTgraph.h"
#include "../data_structure/Clique.h"

class AlgorithmLogic{
    unsigned CCTime;
    double diameterTime;
    unsigned cliqueBruteForceTime;
    unsigned cliqueHeuristicTime;
    unsigned MSTCCTime;
    unsigned MSTGraphTime;

public:
    void computeConnectedComponents(Graph* graph); // return value: execution time

    unsigned computeDiameterGraph(Graph* graph); // return value: diameter & average execution time

    std::vector<std::vector<unsigned> >computeCliquesBruteForce(const Graph* graph); // return value: cliques & execution time

    std::vector<Clique*> computeCliquesHeuristic(Graph* graph); // return value: cliques & execution time

    MSTgraph* MSTonConnectedComponents(Graph* graph); // return value: MST & execution time

    MSTgraph* MSTonGraph(MSTgraph* mstGraph); // return value: MST & execution time

    unsigned int getCCTime() const;

    double getDiameterTime() const;

    unsigned int getCliqueBruteForceTime() const;

    unsigned int getCliqueHeuristicTime() const;

    unsigned int getMSTCCTime() const;

    unsigned int getMSTGraphTime() const;
};



#endif //AAL_TESTED_H
