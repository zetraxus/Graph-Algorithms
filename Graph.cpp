//
// Created by adam on 03.12.18.
//

#include "Graph.h"
#include "Vertex.h"

Graph::Graph(){
    verticesCount = 0;
    edgesCount = 0;
}

void Graph::setVerticesCount(unsigned verticesCount) {
    this->verticesCount = verticesCount;
    vertices.resize(verticesCount);

    for (int i = 0; i < verticesCount; ++i){
        vertices[i] = new Vertex(i);
    }
}

void Graph::addEdge(unsigned v1, unsigned v2, unsigned value) {
    Vertex* vertex1 = vertices[v1];
    Vertex* vertex2 = vertices[v2];

    vertex1->addEdge(vertex2, value);
    vertex2->addEdge(vertex1, value); //undirected graph

    ++edgesCount;
}

unsigned Graph::getVerticesCount() const {
    return verticesCount;
}

Vertex* Graph::getVertex(int index){
    return vertices[index];
}

void Graph::setConnectedComponents(int connectedComponents) {
    Graph::connectedComponents = connectedComponents;
    connectedComponentsList.resize(connectedComponents);
}

void Graph::addToConnectedComponentList(Vertex *vertex, unsigned connectedComponentID) {
    connectedComponentsList[connectedComponentID].push_back(vertex);
}

unsigned Graph::getConnectedComponents() const {
    return connectedComponents;
}

Vertex* Graph::getVertexFromConnectedComponentsList(unsigned connectedComponent, unsigned index) {
    return connectedComponentsList[connectedComponent][index];
}

unsigned Graph::getConnectedComponentsSize(unsigned index) const{
    return connectedComponentsList[index].size();
}
