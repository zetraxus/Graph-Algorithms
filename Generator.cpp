//
// Created by adam on 17.12.18.
//

#include "Generator.h"

Graph** Generator::getGraphs() {
    return graphs;
}

Graph* Generator::generateGraph(bool isDense, unsigned verticesCount) {
    unsigned maxVertices = verticesCount * (verticesCount - 1) / 2;
    unsigned edges = rand() % (maxVertices / 2);
    if (isDense == true)
        edges += maxVertices / 2;
    Graph* newGraph = new Graph(verticesCount, edges);

    std::vector<std::pair<unsigned, unsigned> > temp;
    for (unsigned i = 0; i < verticesCount; ++i) {
        for (unsigned j = i + 1; j < verticesCount; ++j) {
            temp.push_back(std::make_pair(i, j));
        }
    }

    for (int i = 0; i < edges; ++i) {
        unsigned newEdgeIndex = rand() % (edges - i);
        unsigned value = (rand() % MAXEDGEVALUE) + 1;

        newGraph->addEdge(temp[newEdgeIndex].first, temp[newEdgeIndex].second, value);
        temp[newEdgeIndex] = temp[maxVertices - i - 1];
    }

    return newGraph;
}

void Generator::generateAll() {
    graphs = new Graph* [graphsCount];
    unsigned vertices = minimumVerticesCount;

    for (int i = 0; i < graphsCount; ++i) {
        if (i % graphsOnStep == 0 && i != 0)
            vertices *= stepSize;
        if (i % graphsOnStep < graphsOnStep / 2)
            graphs[i] = generateGraph(DENSE, minimumVerticesCount + vertices);
        else
            graphs[i] = generateGraph(SPARSE, minimumVerticesCount + vertices);
    }

}

Generator::Generator(unsigned graphs, unsigned minimumVertices, unsigned step, unsigned graphsOnStep) : graphsCount(
        graphsCount), minimumVerticesCount(minimumVerticesCount), stepSize(step), graphsOnStep(graphsOnStep) {}
