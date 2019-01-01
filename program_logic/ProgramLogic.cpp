//
// Created by adam on 31.12.18.
//

#include "ProgramLogic.h"
#include <algorithm>
#include <fstream>
#include "../in_out/InOut.h"
#include "../generator/Generator.h"
#include "../algorithm/Implementation.h"
#include "../algorithm/AlgorithmLogic.h"
#include "../generator/Generator.h"
#include "../data_structure/MSTgraph.h"

void ProgramLogic::inputFromFileExecute(){
    unsigned diameter;
    MSTgraph* mstGraph;
    std::vector<Clique*> cliquesHeur;
    AlgorithmLogic* algorithmLogic = new AlgorithmLogic();

    std::fstream inputFile;
    std::ofstream outputFile;
    std::string outputFileName(fileName);
    outputFileName.append(".out");

    if(openFiles(inputFile, outputFile, fileName, outputFileName)){
        Graph* graph = new Graph();

        readData(graph, inputFile);
        run(algorithmLogic, graph, diameter, cliquesHeur, mstGraph);
        printResults(outputFile, 0, diameter, algorithmLogic, graph, mstGraph, false);

        delete graph;
    }
}

void ProgramLogic::inputFromCommandLineExecute(){
    Graph* graph = new Graph(); //TODO
    readData(graph);

}

void ProgramLogic::generateInputExecute(bool timeMeasure){
    srand(time(NULL));
    Generator* generator = new Generator();
    generator->generateAll();

    const unsigned files = 2 * generator->getGraphsCount() / generator->getGraphsOnStep();
    const unsigned graphsInFile = generator->getGraphsOnStep() / 2;
    const std::vector<std::string> inputFilesNames = generator->getInputFileNames();
    const std::vector<std::string> outputFilesNames = generator->getOutputFileNames();
    std::vector<std::vector<unsigned> > cliquesBrute;
    std::vector<Clique*> cliquesHeur;

    std::fstream inputFile;
    std::ofstream outputFile;
    unsigned diameter;
    MSTgraph* mstGraph;
    AlgorithmLogic* algorithmLogic = new AlgorithmLogic();

    for (unsigned i = 0; i < files; ++i) {
        openFiles(inputFile, outputFile, "cmake-build-debug/" + inputFilesNames[i], "cmake-build-debug/" + outputFilesNames[i]); //TODO delete cmake-build-debug

        for (unsigned j = 0; j < graphsInFile; ++j) {
            Graph* graph = new Graph();

            readData(graph, inputFile);
            run(algorithmLogic, graph, diameter, cliquesHeur, mstGraph);
            printResults(outputFile, j, diameter, algorithmLogic, graph, mstGraph, timeMeasure);

            delete graph;
        }
        inputFile.close();
        outputFile.close();
    }

    delete algorithmLogic;
}

void ProgramLogic::execute(){
    if(mode == inputFromFile)
        inputFromFileExecute();
    else if(mode == inputFromCommandLine)
        inputFromCommandLineExecute();
    else if(mode == generateInput)
        generateInputExecute(false);
    else
        generateInputExecute(true);
}

void ProgramLogic::setMode(Mode mode) {
    ProgramLogic::mode = mode;
}

void ProgramLogic::setFileName(const char* fileName) {
    ProgramLogic::fileName = fileName;
}

void ProgramLogic::run(AlgorithmLogic*& algorithmLogic, Graph*& graph, unsigned &diameter, std::vector<Clique*>& cliquesHeur, MSTgraph*& mstGraph){
    algorithmLogic->computeConnectedComponents(graph);
    diameter = algorithmLogic->computeDiameterGraph(graph);
//            cliquesBrute = computeCliquesBruteForce(graph);
    cliquesHeur = algorithmLogic->computeCliquesHeuristic(graph);
    mstGraph = algorithmLogic->MSTonConnectedComponents(graph);
    algorithmLogic->MSTonGraph(mstGraph);
}