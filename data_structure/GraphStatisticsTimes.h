//
// Created by adam on 02.01.19.
//

#ifndef AAL_GRAPHSTATISTICSTIMES_H
#define AAL_GRAPHSTATISTICSTIMES_H


class GraphStatisticsTimes {
    unsigned CCTime;
    double diameterTime;
    unsigned cliqueBruteForceTime;
    unsigned cliqueHeuristicTime;
    unsigned MSTCCTime;
    unsigned MSTGraphTime;

public:
    unsigned int getCCTime() const;

    void setCCTime(unsigned int CCTime);

    double getDiameterTime() const;

    void setDiameterTime(double diameterTime);

    unsigned int getCliqueBruteForceTime() const;

    void setCliqueBruteForceTime(unsigned int cliqueBruteForceTime);

    unsigned int getCliqueHeuristicTime() const;

    void setCliqueHeuristicTime(unsigned int cliqueHeuristicTime);

    unsigned int getMSTCCTime() const;

    void setMSTCCTime(unsigned int MSTCCTime);

    unsigned int getMSTGraphTime() const;

    void setMSTGraphTime(unsigned int MSTGraphTime);

    unsigned getMSTTime();
};


#endif //AAL_GRAPHSTATISTICSTIMES_H
