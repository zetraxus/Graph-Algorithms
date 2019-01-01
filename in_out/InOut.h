//
// Created by adam on 05.12.18.
//

#ifndef AAL_IN_OUT_H
#define AAL_IN_OUT_H

#include "../data_structure/Graph.h"
#include "../algorithm/AlgorithmLogic.h"

void readData(Graph* graph, std::fstream& inputStream);

void readData(Graph* graph);

void printResults(std::ofstream& outputFile, const unsigned index, const unsigned diameter, AlgorithmLogic*& algorithmLogic, Graph*& graph, MSTgraph*& mstGraph, bool time);

void printResults(const unsigned diameter, AlgorithmLogic*& algorithmLogic, Graph*& graph, MSTgraph*& mstGraph);

bool openFiles(std::fstream& inputFile, std::ofstream& outputFile, std::string inFileName, std::string outFileName);

#endif //AAL_IN_OUT_H
