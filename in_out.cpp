//
// Created by adam on 05.12.18.
//

#include <iostream>
#include "in_out.h"

void read_data(Graph *graph) {
    unsigned vertices, edges, v1, v2, edgeValue;

    std::cin >> vertices >> edges;

    graph->setVerticesCount(vertices);

    for (int i = 0; i < edges; ++i) {
        std::cin >> v1 >> v2 >> edgeValue;
        graph->addEdge(v1, v2, edgeValue);
    }
}
