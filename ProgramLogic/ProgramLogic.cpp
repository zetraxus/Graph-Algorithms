//
// Created by adam on 31.12.18.
//

#include "ProgramLogic.h"
#include "../InOut/InOut.h"
#include "../Generator/Generator.h"
#include <fstream>

void ProgramLogic::inputFromFileExecute() {
    unsigned diameter;
    MSTgraph* mstGraphKruskal;
    MSTgraph* mstGraphPrim;
    AlgorithmLogic* algorithmLogic = new AlgorithmLogic();

    std::fstream inputFile;
    std::ofstream outputFile;
    std::string outputFileName(fileName);
    outputFileName.append(".out");

    if (openFiles(inputFile, outputFile, fileName, outputFileName)) {
        Graph* graph = new Graph();

        readData(graph, inputFile);
        run(algorithmLogic, graph, diameter, mstGraphKruskal, mstGraphPrim);
        printResults(outputFile, 0, diameter, graph, mstGraphKruskal, mstGraphPrim, false);

        delete mstGraphKruskal;
        delete mstGraphPrim;
        delete graph;
    }

    delete algorithmLogic;
}

void ProgramLogic::inputFromCommandLineExecute() {
    unsigned diameter;
    MSTgraph* mstGraphKruskal;
    MSTgraph* mstGraphPrim;
    AlgorithmLogic* algorithmLogic = new AlgorithmLogic();

    Graph* graph = new Graph();

    readData(graph);
    run(algorithmLogic, graph, diameter, mstGraphKruskal, mstGraphPrim);
    printResults(diameter, graph, mstGraphKruskal, mstGraphPrim);

    delete mstGraphKruskal;
    delete mstGraphPrim;
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
    std::vector<unsigned> time(4); // cc + diameter + mst kruskal + mst prima

    std::fstream inputFile;
    std::ofstream outputFile, timeFile;
    unsigned diameter;
    MSTgraph* mstGraphKruskal;
    MSTgraph* mstGraphPrim;
    AlgorithmLogic* algorithmLogic = new AlgorithmLogic();

    if(timeMeasure && !openFile(timeFile, DIRECTORYINPUTFILES + "/results"))
        return;

    for (unsigned i = 0; i < files; ++i) {
        std::cout << i+1 << "/" << files <<std::endl;
        for(unsigned j = 0 ; j < time.size(); ++j)
            time[j] = 0;

        if (openFiles(inputFile, outputFile, inputFilesNames[i], outputFilesNames[i])) {
            for (unsigned j = 0; j < graphsInFile; ++j) {
                Graph* graph = new Graph();

                readData(graph, inputFile);
                run(algorithmLogic, graph, diameter, mstGraphKruskal, mstGraphPrim);
                printResults(outputFile, j, diameter, graph, mstGraphKruskal, mstGraphPrim, timeMeasure);

                time[0] += graph->getTime().getCCTime();
                time[1] += graph->getTime().getDiameterTime();
                time[2] += graph->getTime().getMSTCCKruskalTime() + graph->getTime().getMSTGraphTime();
                time[3] += graph->getTime().getMSTCCPrimTime() + graph->getTime().getMSTGraphTime();

                delete mstGraphKruskal;
                delete mstGraphPrim;
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

    delete generator;
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

void ProgramLogic::run(AlgorithmLogic*& algorithmLogic, Graph*& graph, unsigned& diameter, MSTgraph*& mstGraphKruskal, MSTgraph*& mstGraphPrim) {
    algorithmLogic->computeConnectedComponents(graph);
    diameter = algorithmLogic->computeDiameterGraph(graph);
    mstGraphKruskal = algorithmLogic->MSTonConnectedComponentsKruskal(graph);
    algorithmLogic->MSTonGraph(mstGraphKruskal, graph);
    mstGraphPrim = algorithmLogic->MSTonConnectedComponentsPrim(graph);
    algorithmLogic->MSTonGraph(mstGraphPrim, graph);
}