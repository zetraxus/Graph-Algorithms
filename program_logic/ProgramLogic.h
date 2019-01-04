//
// Created by adam on 31.12.18.
//

#ifndef AAL_PROGRAMLOGIC_H
#define AAL_PROGRAMLOGIC_H


#include <string>
#include "../algorithm/AlgorithmLogic.h"

class ProgramLogic {

public:
    enum Mode {
        inputFromFile,
        inputFromCommandLine,
        generateInput,
        generateInputAndMeasureTime,
    };

private:
    const char* fileName;
    Mode mode;

    void run(AlgorithmLogic*& algorithmLogic, Graph*& graph, unsigned& diameter, std::vector<Clique*>& cliquesHeur, MSTgraph*& mstGraphKruskal, MSTgraph*& mstGraphPrim);

public:
    void inputFromFileExecute();

    void inputFromCommandLineExecute();

    void generateInputExecute(bool timeMeasure);

    void execute();

    void setMode(Mode mode);

    void setFileName(const char* fileName);
};


#endif //AAL_PROGRAMLOGIC_H
