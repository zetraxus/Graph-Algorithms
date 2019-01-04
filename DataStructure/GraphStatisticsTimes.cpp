//
// Created by adam on 02.01.19.
//

#include "GraphStatisticsTimes.h"

unsigned int GraphStatisticsTimes::getCCTime() const {
    return CCTime;
}

void GraphStatisticsTimes::setCCTime(unsigned int CCTime) {
    GraphStatisticsTimes::CCTime = CCTime;
}

unsigned GraphStatisticsTimes::getDiameterTime() const {
    return diameterTime;
}

void GraphStatisticsTimes::setDiameterTime(unsigned diameterTime) {
    GraphStatisticsTimes::diameterTime = diameterTime;
}

void GraphStatisticsTimes::setCliqueBruteForceTime(unsigned int cliqueBruteForceTime) {
    GraphStatisticsTimes::cliqueBruteForceTime = cliqueBruteForceTime;
}

void GraphStatisticsTimes::setCliqueHeuristicTime(unsigned int cliqueHeuristicTime) {
    GraphStatisticsTimes::cliqueHeuristicTime = cliqueHeuristicTime;
}

void GraphStatisticsTimes::setMSTCCKruskalTime(unsigned int MSTCCKruskalTime) {
    GraphStatisticsTimes::MSTCCKruskalTime = MSTCCKruskalTime;
}

void GraphStatisticsTimes::setMSTCCPrimTime(unsigned int MSTCCPrimTime) {
    GraphStatisticsTimes::MSTCCPrimTime = MSTCCPrimTime;
}

unsigned int GraphStatisticsTimes::getMSTGraphTime() const {
    return MSTGraphTime;
}

void GraphStatisticsTimes::setMSTGraphTime(unsigned int MSTGraphTime) {
    GraphStatisticsTimes::MSTGraphTime = MSTGraphTime;
}

unsigned int GraphStatisticsTimes::getMSTCCKruskalTime() const {
    return MSTCCKruskalTime;
}

unsigned int GraphStatisticsTimes::getMSTCCPrimTime() const {
    return MSTCCPrimTime;
}
