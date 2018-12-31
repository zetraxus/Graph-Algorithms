//
// Created by adam on 31.12.18.
//

#include "ProgramLogic.h"
#include <algorithm>
#include <fstream>
#include "../in_out/in_out.h"
#include "../generator/Generator.h"
#include "../algorithm/Implementation.h"
#include "../algorithm/AlgorithmLogic.h"
#include "../generator/Generator.h"
#include "../data_structure/MSTgraph.h"

void ProgramLogic::inputFromFileExecute(){

}

void ProgramLogic::inputFromCommandLineExecute(){

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
        inputFile.open("cmake-build-debug/" + inputFilesNames[i]); //TODO delete cmake-build-debug
        outputFile.open("cmake-build-debug/" + outputFilesNames[i]); //TODO delete cmake-build-debug

        if (!inputFile.is_open())
            std::cerr << ERRORFILEOPEN << inputFilesNames[i] << std::endl;
        if (!outputFile.is_open()) {
            std::cerr << ERRORFILEOPEN << outputFilesNames[i] << std::endl;
        }

        for (unsigned j = 0; j < graphsInFile; ++j) {
            Graph* graph = new Graph();

            read_data(graph, inputFile);

            std::cout << i << " " << j << std::endl;
            algorithmLogic->computeConnectedComponents(graph);
            diameter = algorithmLogic->computeDiameterGraph(graph);
//            cliquesBrute = computeCliquesBruteForce(graph);
            cliquesHeur = algorithmLogic->computeCliquesHeuristic(graph);
            mstGraph = algorithmLogic->MSTonConnectedComponents(graph);
            algorithmLogic->MSTonGraph(mstGraph);

            if(timeMeasure){
                outputFile << GRAPHDESCRIPTION << j << ":" << NEWLINE;
                outputFile << DIAMETER << diameter << AVGTIME << algorithmLogic->getDiameterTime() << NEWLINE;
                outputFile << CONNECTEDCOMPONENTS << graph->getConnectedComponentsCount() << NEWLINE;
                outputFile << MSTONGRAPH << mstGraph->getMSTValue() << TIME << algorithmLogic->getMSTCCTime() + algorithmLogic->getMSTGraphTime() << NEWLINE;
                outputFile << NEWLINE;
            }
            else{
                outputFile << GRAPHDESCRIPTION << j << ":" << NEWLINE;
                outputFile << DIAMETER << diameter << NEWLINE;
                outputFile << CONNECTEDCOMPONENTS << graph->getConnectedComponentsCount() << NEWLINE;
                outputFile << MSTONGRAPH << mstGraph->getMSTValue();
                outputFile << NEWLINE;
            }

            delete graph;
        }
        inputFile.close();
        outputFile.close();
    }
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
