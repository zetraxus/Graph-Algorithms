//
// Created by adam on 07.12.18.
//
#include <queue>
#include <climits>
#include "Algorithms.h"

void DFS(Graph* graph) {

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

    graph->setConnectedComponentsCount(connectedComponents);

    for (unsigned i = 0; i < graph->getVerticesCount(); ++i) {
        graph->addToConnectedComponentList(graph->getVertex(i), graph->getVertex(i)->getConnectedComponentID());
    }

}

void DFSVisit(Graph* graph, Vertex* vertex, unsigned connectedComponents) {
    vertex->setColour(Vertex::GREY);
    vertex->setConnectedComponentID(connectedComponents);
    for (unsigned i = 0; i < vertex->getDegree(); ++i) {
        if (vertex->getNeighbour(i)->getColour() == Vertex::WHITE)
            DFSVisit(graph, vertex->getNeighbour(i), connectedComponents);
    }
    vertex->setColour(Vertex::BLACK);
}

unsigned BFS(ConnectedComponent* connectedComponent, Vertex* start) {
    for (int i = 0; i < connectedComponent->getSize(); ++i) {
        connectedComponent->getVertex(i)->setDistance(UINT_MAX);
        connectedComponent->getVertex(i)->setColour(Vertex::WHITE);
    }

    start->setColour(Vertex::GREY);
    start->setDistance(0);

    std::queue<Vertex*> queue;
    queue.push(start);
    Vertex* analyzed;
    unsigned lastAnalysedVertexDistance = 0;
    while (!queue.empty()) {
        analyzed = queue.front();

        for (int i = 0; i < analyzed->getDegree(); ++i) {
            if (analyzed->getNeighbour(i)->getColour() == Vertex::WHITE) {
                analyzed->getNeighbour(i)->setColour(Vertex::GREY);
                analyzed->getNeighbour(i)->setDistance(analyzed->getDistance() + 1);
                queue.push(analyzed->getNeighbour(i));
            }
        }

        queue.pop();
        analyzed->setColour(Vertex::BLACK);
        lastAnalysedVertexDistance = analyzed->getDistance();
    }

    return lastAnalysedVertexDistance;
}



