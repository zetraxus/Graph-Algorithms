//
// Created by adam on 05.12.18.
//

#include <iostream>
#include <fstream>
#include "InOut.h"
#include "../messages/Messages.h"

void readData(Graph* graph, std::fstream& inputStream) {
    unsigned vertices, edges, v1, v2, edgeValue;

    inputStream >> vertices >> edges;

    graph->setVerticesCount(vertices);

    for (int i = 0; i < edges; ++i) {
        inputStream >> v1 >> v2 >> edgeValue;
        graph->addEdge(v1, v2, edgeValue);
    }
}

void readData(Graph* graph) {
    unsigned vertices, edges, v1, v2, edgeValue;

    std::cin >> vertices >> edges;

    graph->setVerticesCount(vertices);

    for (int i = 0; i < edges; ++i) {
        std::cin >> v1 >> v2 >> edgeValue;
        graph->addEdge(v1, v2, edgeValue);
    }
}

void printResults(std::ofstream& outputFile, const unsigned index, const unsigned diameter, AlgorithmLogic*& algorithmLogic, Graph*& graph, MSTgraph*& mstGraph, bool time) {
    if (time) {
        outputFile << GRAPHDESCRIPTION << index << ":" << NEWLINE;
        outputFile << CONNECTEDCOMPONENTS << graph->getConnectedComponentsCount() << SPACE << TIMEMICROSECONDS  << graph->getTimes().getCCTime() << SPACE << TIMEMILLISECONDS << graph->getTimes().getCCTime()/1000 << NEWLINE;
        outputFile << DIAMETER << diameter << TIMEMICROSECONDS << graph->getTimes().getDiameterTime() << SPACE << TIMEMILLISECONDS << graph->getTimes().getDiameterTime()/1000<< NEWLINE;
        outputFile << MSTONGRAPH << mstGraph->getMSTValue() << TIMEMICROSECONDS << graph->getTimes().getMSTTime() << SPACE << TIMEMILLISECONDS << graph->getTimes().getMSTTime()/1000<< NEWLINE;
        outputFile << NEWLINE << NEWLINE;
    } else {
        outputFile << GRAPHDESCRIPTION << index << ":" << NEWLINE;
        outputFile << CONNECTEDCOMPONENTS << graph->getConnectedComponentsCount() << NEWLINE;
        outputFile << DIAMETER << diameter << NEWLINE;
        outputFile << MSTONGRAPH << mstGraph->getMSTValue();
        outputFile << NEWLINE << NEWLINE;
    }
}

void printResults(const unsigned diameter, AlgorithmLogic*& algorithmLogic, Graph*& graph, MSTgraph*& mstGraph) {
    std::cout << NEWLINE << DIAMETER << diameter << NEWLINE;
    std::cout << CONNECTEDCOMPONENTS << graph->getConnectedComponentsCount() << NEWLINE;
    std::cout << MSTONGRAPH << mstGraph->getMSTValue();
    std::cout << NEWLINE << NEWLINE;
}

bool openFiles(std::fstream& inputFile, std::ofstream& outputFile, std::string inFileName, std::string outFileName) {
    inputFile.open(inFileName);
    outputFile.open(outFileName);

    if (!inputFile.is_open()) {
        std::cerr << ERROROPENFILE << inFileName << NEWLINE;
        return false;
    }
    if (!outputFile.is_open()) {
        std::cerr << ERROROPENFILE << outFileName << NEWLINE;
        return false;
    }
    return true;
}