//
// Created by adam on 07.12.18.
//
#include <queue>
#include <climits>
#include "Implementation.h"

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

const std::vector< std::vector<unsigned> > getAllSubsets(unsigned setSize) {
    std::vector<int> set;
    for(int i = 0 ; i < setSize; ++i)
        set.push_back(i);

    std::vector<std::vector<unsigned> > subset;
    std::vector<unsigned> empty;
    subset.push_back(empty);

    for (unsigned i = 0; i < set.size(); ++i) {
        std::vector<std::vector<unsigned> > subsetTemp = subset;

        for (unsigned j = 0; j < subsetTemp.size(); j++)
            subsetTemp[j].push_back(set[i]);

        for (unsigned j = 0; j < subsetTemp.size(); ++j)
            subset.push_back(subsetTemp[j]);
    }

//    for (unsigned i = 0 ; i < subset.size(); ++i){
//        for (unsigned j = 0 ; j < subset[i].size(); ++j){
//            std::cout<<subset[i][j] << " ";
//        }
//        std::cout<<std::endl;
//    }

    return subset;
}