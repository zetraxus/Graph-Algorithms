//
// Created by adam on 23.12.18.
//

#include "MSTgraph.h"

const unsigned MINEDGEVALUE = 1;

void MSTgraph::addVectorToMSTonCC(std::vector<edgeDef> nextMSTonCC) {
    MSTonCC.push_back(nextMSTonCC);
    for (auto& el : nextMSTonCC)
        MSTonGraph.push_back(el);
}

void MSTgraph::addToIsolatedVertices(unsigned vertexId) {
    isolatedVertices.push_back(vertexId);
}

void MSTgraph::computeMSTonGraph() {
    for (int i = 1; i < MSTonCC.size(); ++i) {
        edgeDef newEdge = std::make_pair(MINEDGEVALUE, std::make_pair(MSTonCC[i - 1][0].second.first, MSTonCC[i][0].second.first));
        MSTonGraph.push_back(newEdge);
    }

    for (unsigned i = 0; i < isolatedVertices.size(); ++i) {
        edgeDef newEdge;
        if (MSTonGraph.empty()) {
            newEdge = std::make_pair(MINEDGEVALUE, std::make_pair(isolatedVertices[i], isolatedVertices[i + 1]));
            ++i;
        } else
            newEdge = std::make_pair(MINEDGEVALUE, std::make_pair(isolatedVertices[i], MSTonGraph[0].second.first));

        MSTonGraph.push_back(newEdge);
    }
}

void MSTgraph::print() const {
    std::cout << "MST print: " << std::endl;
    for (unsigned i = 0; i < MSTonGraph.size(); ++i) {
        std::cout << MSTonGraph[i].second.first << " " << MSTonGraph[i].second.second << " val = " << MSTonGraph[i].first << std::endl;
    }
}

unsigned MSTgraph::getMSTValue() const {
    unsigned mstVal = 0;
    for (int i = 0; i < MSTonGraph.size(); ++i) {
        mstVal += MSTonGraph[i].first;
    }
    return mstVal;
}