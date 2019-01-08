//
// Created by adam on 02.01.19.
//

#ifndef AAL_GRAPHSTATISTICSTIMES_H
#define AAL_GRAPHSTATISTICSTIMES_H


class GraphStatisticsTimes {
    unsigned CCTime;
    unsigned diameterTime;
    unsigned cliqueBruteForceTime;
    unsigned MSTCCKruskalTime;
    unsigned MSTCCPrimTime;
    unsigned MSTGraphTime;

public:
    unsigned int getCCTime() const;

    void setCCTime(unsigned int CCTime);

    unsigned getDiameterTime() const;

    void setDiameterTime(unsigned diameterTime);

    void setCliqueBruteForceTime(unsigned int cliqueBruteForceTime);

    void setMSTCCKruskalTime(unsigned int MSTCCKruskalTime);

    void setMSTCCPrimTime(unsigned int MSTCCPrimTime);

    unsigned int getMSTGraphTime() const;

    void setMSTGraphTime(unsigned int MSTGraphTime);

    unsigned int getMSTCCKruskalTime() const;

    unsigned int getMSTCCPrimTime() const;
};


#endif //AAL_GRAPHSTATISTICSTIMES_H
