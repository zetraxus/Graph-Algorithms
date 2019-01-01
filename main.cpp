#include <fstream>
#include <getopt.h>
#include <iostream>
#include "messages/Messages.h"
#include "program_logic/ProgramLogic.h"


int main(int argc, char** argv) {
    ProgramLogic* programme = new ProgramLogic();
    int opt;
    opterr = 0;
    unsigned options = 0;

    while((opt=getopt(argc, argv, "a:bcd")) != -1){
        switch (opt){
            case 'a':
                programme->setMode(ProgramLogic::Mode::inputFromFile);
                programme->setFileName(optarg);
                break;
            case 'b':
                programme->setMode(ProgramLogic::Mode::inputFromCommandLine);
                break;
            case 'c':
                programme->setMode(ProgramLogic::Mode::generateInput);
                break;
            case 'd':
                programme->setMode(ProgramLogic::Mode::generateInputAndMeasureTime);
                break;
            case '?':
                if(optopt == 'a'){
                    std::cerr << "Option 'a' requires an argument (file name)" << NEWLINE;
                    return 1;
                }
                else{
                    std::cerr << "Uknown option: " << char(optopt) << NEWLINE;
                    return 1;
                }
        }

        ++options;
    }

    if(options != 1){
        std::cerr << BADFLAGS << NEWLINE;
        return 1;
    }

    programme->execute();
    return 0;
}