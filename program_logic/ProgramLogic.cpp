//
// Created by adam on 31.12.18.
//

#include "ProgramLogic.h"
#include <fstream>
#include "../generator/Generator.h"
#include "../in_out/InOut.h"

void ProgramLogic::inputFromFileExecute() {
    unsigned diameter;
    MSTgraph* mstGraph;
    std::vector<Clique*> cliquesHeur;
    AlgorithmLogic* algorithmLogic = new AlgorithmLogic();

    std::fstream inputFile;
    std::ofstream outputFile;
    std::string outputFileName(fileName);
    outputFileName.append(".out");

    if (openFiles(inputFile, outputFile, fileName, outputFileName)) {
        Graph* graph = new Graph();

        readData(graph, inputFile);
        run(algorithmLogic, graph, diameter, cliquesHeur, mstGraph);
        printResults(outputFile, 0, diameter, graph, mstGraph, false);

        delete graph;
    }

    delete algorithmLogic;
}

void ProgramLogic::inputFromCommandLineExecute() {
    unsigned diameter;
    MSTgraph* mstGraph;
    std::vector<Clique*> cliquesHeur;
    AlgorithmLogic* algorithmLogic = new AlgorithmLogic();

    Graph* graph = new Graph();

    readData(graph);
    run(algorithmLogic, graph, diameter, cliquesHeur, mstGraph);
    printResults(diameter, graph, mstGraph);

    delete graph;
    delete algorithmLogic;
}

void ProgramLogic::generateInputExecute(bool timeMeasure) {
    srand(time(NULL));
    Generator* generator = new Generator();
    generator->generateAll();

    const unsigned files = 2 * generator->getGraphsCount() / generator->getGraphsOnStep();
    const unsigned graphsInFile = generator->getGraphsOnStep() / 2;
    const std::vector<std::string> inputFilesNames = generator->getInputFileNames();
    const std::vector<std::string> outputFilesNames = generator->getOutputFileNames();
    const std::vector<std::string>& descriptions = generator->getFilesDescriptions();
    std::vector<std::vector<unsigned> > cliquesBrute;
    std::vector<Clique*> cliquesHeur;
    std::vector<unsigned> time(4); // cc + diameter + mst kruskal + mst prima

    std::fstream inputFile;
    std::ofstream outputFile, timeFile;
    unsigned diameter;
    MSTgraph* mstGraph;
    AlgorithmLogic* algorithmLogic = new AlgorithmLogic();

    if(timeMeasure && !openFile(timeFile, DIRECTORYINPUTFILES + "/results"))
        return;

    for (unsigned i = 0; i < 4; ++i) {
        for(unsigned t: time)
            t = 0;

        if (openFiles(inputFile, outputFile, inputFilesNames[i], outputFilesNames[i])) {
            for (unsigned j = 0; j < graphsInFile; ++j) {
                std::cout << i << " " << j << NEWLINE;
                Graph* graph = new Graph();

                readData(graph, inputFile);
                run(algorithmLogic, graph, diameter, cliquesHeur, mstGraph);
                printResults(outputFile, j, diameter, graph, mstGraph, timeMeasure);

                time[0] += graph->getTime().getCCTime();
                time[1] += graph->getTime().getDiameterTime();
                time[2] += graph->getTime().getMSTTime();
                // + time[3] algorithm prima

                delete graph;
            }

            if(timeMeasure)
                printMeasuringTime(timeFile, time, graphsInFile, descriptions[i]);

            inputFile.close();
            outputFile.close();
        }
    }

    if(timeMeasure)
        timeFile.close();

    delete algorithmLogic;
}

void ProgramLogic::execute() {
    if (mode == inputFromFile)
        inputFromFileExecute();
    else if (mode == inputFromCommandLine)
        inputFromCommandLineExecute();
    else if (mode == generateInput)
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

void ProgramLogic::run(AlgorithmLogic*& algorithmLogic, Graph*& graph, unsigned& diameter, std::vector<Clique*>& cliquesHeur, MSTgraph*& mstGraph) {
    algorithmLogic->computeConnectedComponents(graph);
    diameter = algorithmLogic->computeDiameterGraph(graph);
//    cliquesBrute = computeCliquesBruteForce(graph);
    cliquesHeur = algorithmLogic->computeCliquesHeuristic(graph);
    mstGraph = algorithmLogic->MSTonConnectedComponents(graph);
    algorithmLogic->MSTonGraph(mstGraph, graph);
}