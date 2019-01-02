//
// Created by adam on 19.12.18.
//

#ifndef AAL_MESSAGES_H
#define AAL_MESSAGES_H

#include <string>

const std::string SPACE = " ";
const std::string NEWLINE = "\n";
const std::string DIRECTORYINPUTFILES = "input_files";
const std::string FNEXTENSTIONDENSE = ".dense";
const std::string FNEXTENSTIONSPARSE = ".sparse";
const std::string ERRORFILEOPEN = "ERROR_OPEN_FILE ";
const std::string INPUT = "/input";
const std::string OUTPUT = "/output";
const std::string GRAPHDESCRIPTION = "GRAPH_";
const std::string DIAMETER = "Graph diameter: ";
const std::string CONNECTEDCOMPONENTS = "Connected components in graph: ";
const std::string MSTONGRAPH = "MST Value: ";
const std::string TIMEMILLISECONDS = " time[milliseconds]: ";
const std::string TIMEMICROSECONDS = " time[microseconds]: ";
const std::string BADFLAGS = "You should set one flag (a,b,c or d)";

#endif //AAL_MESSAGES_H
