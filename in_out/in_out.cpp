//
// Created by adam on 05.12.18.
//

#include <iostream>
#include <fstream>
#include "in_out.h"

void read_data(Graph* graph, std::fstream& inputStream) {
    unsigned vertices, edges, v1, v2, edgeValue;

    inputStream >> vertices >> edges;

    graph->setVerticesCount(vertices);

    for (int i = 0; i < edges; ++i) {
        inputStream >> v1 >> v2 >> edgeValue;
        graph->addEdge(v1, v2, edgeValue);
    }
}
