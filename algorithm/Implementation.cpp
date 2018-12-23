//
// Created by adam on 07.12.18.
//
#include <queue>
#include <climits>
#include <algorithm>
#include "Implementation.h"

const unsigned DEFAULTRANK = 0;

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
    Vertex* analysed;
    unsigned lastAnalysedVertexDistance = 0;
    while (!queue.empty()) {
        analysed = queue.front();

        for (int i = 0; i < analysed->getDegree(); ++i) {
            if (analysed->getNeighbour(i)->getColour() == Vertex::WHITE) {
                analysed->getNeighbour(i)->setColour(Vertex::GREY);
                analysed->getNeighbour(i)->setDistance(analysed->getDistance() + 1);
                queue.push(analysed->getNeighbour(i));
            }
        }

        queue.pop();
        analysed->setColour(Vertex::BLACK);
        lastAnalysedVertexDistance = analysed->getDistance();
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

    return subset;
}

std::vector<edgeDef> getEdges(const ConnectedComponent* connectedComponent){
    const std::vector<Vertex*> vertices = connectedComponent->getVertices();
    std::vector<edgeDef> result;

    for(unsigned i = 0 ; i < vertices.size(); ++i){
        const std::vector<vuPair>& neighbours = vertices[i]->getConnectedVertices();
        for(int j = 0 ; j < neighbours.size(); ++j){
            if(vertices[i]->getId() < neighbours[j].first->getId())
                result.push_back(std::make_pair(neighbours[j].second, std::make_pair(vertices[i]->getId(), neighbours[j].first->getId())));
        }
    }
    return result;
}

void MakeSet(std::vector<unsigned>& ancestors, std::vector<unsigned>& rank, const ConnectedComponent* connectedComponent){
    for(unsigned i = 0 ; i < connectedComponent->getSize(); ++i){
        ancestors[connectedComponent->getVertex(i)->getId()] = connectedComponent->getVertex(i)->getId();
        rank[connectedComponent->getVertex(i)->getId()] = DEFAULTRANK;
    }
}

void Union(unsigned xId, unsigned yId, std::vector<unsigned>& ancestors, std::vector<unsigned>& rank){
    Link(FindSet(xId, ancestors), FindSet(yId, ancestors), ancestors, rank);
}

void Link(unsigned xId, unsigned yId, std::vector<unsigned>& ancestors, std::vector<unsigned>& rank){
    if(rank[xId] > rank[yId])
        ancestors[yId] = xId;
    else
        ancestors[xId] = yId;
    if(rank[xId] == rank[yId])
        ++rank[yId];
}

unsigned FindSet(unsigned xId, std::vector<unsigned>& ancestors){
    if(ancestors[xId] != xId) {
        return FindSet(ancestors[xId], ancestors);
    }
    return ancestors[xId];
}

std::vector<edgeDef> MST(const ConnectedComponent* connectedComponent, unsigned graphSize){
    std::vector<edgeDef> result;

    std::vector<edgeDef> edges = getEdges(connectedComponent);

    std::vector<unsigned> ancestors(graphSize);
    std::vector<unsigned> rank(graphSize);

    std::sort(edges.begin(), edges.end());
    MakeSet(ancestors, rank, connectedComponent);

    for(unsigned i = 0 ; i < edges.size(); ++i){
        if(FindSet(edges[i].second.first, ancestors) != FindSet(edges[i].second.second, ancestors)) {
            Union(edges[i].second.first, edges[i].second.second, ancestors, rank);
            result.push_back(edges[i]);
        }
    }

    return result;
}

std::vector<edgeDef> MST(Graph* graph){

}