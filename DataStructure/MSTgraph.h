//
// Created by adam on 23.12.18.
//

#ifndef AAL_MSTGRAPH_H
#define AAL_MSTGRAPH_H


#include "../algorithm/Implementation.h"

class MSTgraph {

    std::vector<std::vector<edgeDef> > MSTonCC;
    std::vector<unsigned> isolatedVertices;
    std::vector<edgeDef> MSTonGraph;

public:

    void addVectorToMSTonCC(std::vector<edgeDef> nextMSTonCC);

    void addToIsolatedVertices(unsigned vertexId);

    void computeMSTonGraph();

    void print() const;

    unsigned getMSTValue() const;
};


#endif //AAL_MSTGRAPH_H
