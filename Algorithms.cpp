//
// Created by adam on 07.12.18.
//
#include "Algorithms.h"

void preDFS(Graph* graph){

    for (unsigned i = 0; i < graph->getVerticesCount(); ++i){
        graph->getVertex(i)->setColour(Vertex::WHITE);
    }

    unsigned connectedComponents = 0;

    for (unsigned i = 0 ; i < graph->getVerticesCount(); ++i){
        if(graph->getVertex(i)->getColour() == Vertex::WHITE){
            DFS(graph, graph->getVertex(i), connectedComponents);
            ++connectedComponents;
        }
    }
}

void DFS(Graph* graph, Vertex* vertex, const unsigned connectedComponents){
    vertex->setColour(Vertex::GREY);
    vertex->setConnectedComponentID(connectedComponents);
    for(unsigned i = 0 ; i < vertex->getDegree(); ++i){
        if (vertex->getNeighbour(i)->getColour() == Vertex::WHITE)
            DFS(graph, vertex->getNeighbour(i), connectedComponents);
    }
    vertex->setColour(Vertex::BLACK);
}



