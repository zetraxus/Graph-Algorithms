//
// Created by adam on 17.12.18.
//

#include "Generator.h"

Generator::Generator(unsigned int graphsCount) : graphsCount(graphsCount) {}

Graph** Generator::getGraphs() {
    return graphs;
}

Graph* Generator::generateGraph() {
    Graph* newGraph = new Graph();
}

void Generator::generateAll() {

}
