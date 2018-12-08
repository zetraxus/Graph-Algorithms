//
// Created by adam on 07.12.18.
//
#include "Algorithms.h"

void DFS(Graph *graph) {

    for (unsigned i = 0; i < graph->getVerticesCount(); ++i) {
        graph->getVertex(i)->setColour(Vertex::WHITE);
    }

    unsigned connectedComponents = 0;

    for (unsigned i = 0; i < graph->getVerticesCount(); ++i) {
        if (graph->getVertex(i)->getColour() == Vertex::WHITE) {
            DFSVisit(graph, graph->getVertex(i), connectedComponents);
            ++connectedComponents;
        }
    }

    graph->setConnectedComponents(connectedComponents+1);

    for (unsigned i = 0; i < graph->getVerticesCount(); ++i) {
        graph->addToConnectedComponentList(graph->getVertex(i), graph->getVertex(i)->getConnectedComponentID());
    }
}

void DFSVisit(Graph *graph, Vertex *vertex, const unsigned connectedComponents) {
    vertex->setColour(Vertex::GREY);
    vertex->setConnectedComponentID(connectedComponents);
    for (unsigned i = 0; i < vertex->getDegree(); ++i) {
        if (vertex->getNeighbour(i)->getColour() == Vertex::WHITE)
            DFSVisit(graph, vertex->getNeighbour(i), connectedComponents);
    }
    vertex->setColour(Vertex::BLACK);
}

unsigned BFS(Graph *graph, Vertex* start) {
    
}



