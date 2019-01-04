//
// Created by adam on 05.12.18.
//

#include <iostream>
#include <fstream>
#include "InOut.h"
#include "../Messages/Messages.h"

void readData(Graph* graph, std::fstream& inputStream) {
    unsigned vertices, edges, v1, v2, edgeValue;

    inputStream >> vertices >> edges;

    graph->setVerticesCount(vertices);

    for (unsigned i = 0; i < edges; ++i) {
        inputStream >> v1 >> v2 >> edgeValue;
        graph->addEdge(v1, v2, edgeValue);
    }
}

void readData(Graph* graph) {
    unsigned vertices, edges, v1, v2, edgeValue;

    std::cin >> vertices >> edges;

    graph->setVerticesCount(vertices);

    for (unsigned i = 0; i < edges; ++i) {
        std::cin >> v1 >> v2 >> edgeValue;
        graph->addEdge(v1, v2, edgeValue);
    }
}

void printResults(std::ofstream& outputFile, const unsigned index, const unsigned diameter, Graph*& graph, MSTgraph*& mstGraphKruskal, MSTgraph*& mstGraphPrim, bool time) {
    if (time) {
        outputFile << GRAPHDESCRIPTION << index << ":" << NEWLINE;
        outputFile << CONNECTEDCOMPONENTS << graph->getConnectedComponentsCount() << SPACE << TIMEMICROSECONDS  << graph->getTime().getCCTime() << SPACE << TIMEMILLISECONDS << graph->getTime().getCCTime()/1000 << NEWLINE;
        outputFile << DIAMETER << diameter << TIMEMICROSECONDS << graph->getTime().getDiameterTime() << SPACE << TIMEMILLISECONDS << graph->getTime().getDiameterTime()/1000<< NEWLINE;
        outputFile << MSTONGRAPH << mstGraphKruskal->getMSTValue() << TIMEMICROSECONDS << graph->getTime().getMSTCCKruskalTime() + graph->getTime().getMSTGraphTime() << SPACE << TIMEMILLISECONDS << (graph->getTime().getMSTCCKruskalTime() + graph->getTime().getMSTGraphTime())/1000 << NEWLINE;
        outputFile << MSTONGRAPH << mstGraphPrim->getMSTValue() << TIMEMICROSECONDS << graph->getTime().getMSTCCPrimTime() + graph->getTime().getMSTGraphTime() << SPACE << TIMEMILLISECONDS << (graph->getTime().getMSTCCPrimTime() + graph->getTime().getMSTGraphTime())/1000 << NEWLINE;
        outputFile << NEWLINE << NEWLINE;
    } else {
        outputFile << GRAPHDESCRIPTION << index << ":" << NEWLINE;
        outputFile << CONNECTEDCOMPONENTS << graph->getConnectedComponentsCount() << NEWLINE;
        outputFile << DIAMETER << diameter << NEWLINE;
        outputFile << MSTONGRAPH << mstGraphKruskal->getMSTValue();
        outputFile << NEWLINE << NEWLINE;
    }
}

void printResults(const unsigned diameter, Graph*& graph, MSTgraph*& mstGraphKruskal, MSTgraph*& mstGraphPrim) {
    std::cout << NEWLINE << DIAMETER << diameter << NEWLINE;
    std::cout << CONNECTEDCOMPONENTS << graph->getConnectedComponentsCount() << NEWLINE;
    std::cout << MSTONGRAPH << mstGraphKruskal->getMSTValue() << NEWLINE;
    std::cout << MSTONGRAPH << mstGraphPrim->getMSTValue() << NEWLINE << NEWLINE;
    mstGraphPrim->print();
}

void printMeasuringTime(std::ofstream& timeFile, std::vector<unsigned> time, unsigned graphsInFile, std::string description){
    timeFile << description << NEWLINE;
    timeFile << CC + SPACE << time[0]/graphsInFile << TIMEMICROSECONDS << NEWLINE;
    timeFile << DI + SPACE << time[1]/graphsInFile << TIMEMICROSECONDS << NEWLINE;
    timeFile << MSTK + SPACE << time[2]/graphsInFile << TIMEMICROSECONDS << NEWLINE;
    timeFile << MSTP + SPACE << time[3]/graphsInFile << TIMEMICROSECONDS << NEWLINE << NEWLINE;

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

bool openFile(std::ofstream& file, std::string fileName){
    file.open(fileName);
    if(!file.is_open()){
        std::cerr << ERROROPENFILE << fileName << NEWLINE;
        return false;
    }
    return true;
}