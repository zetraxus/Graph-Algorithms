//
// Created by adam on 19.12.18.
//

#ifndef AAL_MESSAGES_H
#define AAL_MESSAGES_H

#include <string>

const std::string SPACE = " ";
const std::string NEWLINE = "\n";
const std::string DIRECTORYINPUTFILES = "in_out_files";
const std::string FNEXTENSTIONDENSE = ".dense";
const std::string FNEXTENSTIONSPARSE = ".sparse";
const std::string VERTICES = "vertices";
const std::string EDGES = "edges";
const std::string ERROROPENFILE = "ERROR_OPEN_FILE ";
const std::string ERRORCREATEDIRECTORY = "ERROR_CREATE_DIRECTORY ";
const std::string INPUT = "/input";
const std::string OUTPUT = "/output";
const std::string GRAPHDESCRIPTION = "GRAPH_";
const std::string DIAMETER = "Graph diameter: ";
const std::string CONNECTEDCOMPONENTS = "Connected components in graph: ";
const std::string MSTONGRAPH = "MST Value: ";
const std::string CC = "CC";
const std::string DI = "DI";
const std::string MSTK = "MSTK";
const std::string MSTP = "MSTP";
const std::string TIMEMILLISECONDS = " time[ms]: ";
const std::string TIMEMICROSECONDS = " time[μs]: ";
const std::string BADFLAGS = "You should set one flag (a,b,c or d)";

#endif //AAL_MESSAGES_H
