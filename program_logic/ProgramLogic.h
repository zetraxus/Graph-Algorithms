//
// Created by adam on 31.12.18.
//

#ifndef AAL_PROGRAMLOGIC_H
#define AAL_PROGRAMLOGIC_H


#include <string>

class ProgramLogic {

public:
    enum Mode{
        inputFromFile,
        inputFromCommandLine,
        generateInput,
        generateInputAndMeasureTime,
    };

private:
    const char* fileName;
    Mode mode;

public:
    void inputFromFileExecute();
    void inputFromCommandLineExecute();
    void generateInputExecute();
    void generateInputAndMeasureTimeExecute();

    void execute();
    void setMode(Mode mode);
    void setFileName(const char* fileName);
};


#endif //AAL_PROGRAMLOGIC_H
