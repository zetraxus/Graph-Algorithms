//
// Created by adam on 05.12.18.
//

#ifndef AAL_IN_OUT_H
#define AAL_IN_OUT_H

#include "../Algorithm/AlgorithmLogic.h"

void readData(Graph* graph, std::fstream& inputStream);

void readData(Graph* graph);

void printResults(std::ofstream& outputFile, unsigned index, unsigned diameter, Graph*& graph, MSTgraph*& mstGraphKruskal, MSTgraph*& mstGraphPrim, bool time);

void printResults(unsigned diameter, Graph*& graph, MSTgraph*& mstGraphKruskal, MSTgraph*& mstGraphPrim);

void printMeasuringTime(std::ofstream& timeFile, std::vector<unsigned> time, unsigned graphsInFile, std::string description);

bool openFiles(std::fstream& inputFile, std::ofstream& outputFile, std::string inFileName, std::string outFileName);

bool openFile(std::ofstream& file, std::string fileName);

#endif //AAL_IN_OUT_H
