//
// Created by adam on 07.12.18.
//

#ifndef AAL_VERTEX_H
#define AAL_VERTEX_H

#include <vector>

class Vertex;

typedef std::pair<Vertex *, unsigned> vuPair; //connected vertex and value of edge

class Vertex {

public :

    enum Colour {
        WHITE,
        GREY,
        BLACK
    };

private:

    unsigned id;
    std::vector<vuPair> connectedVertex;

    unsigned connectedComponentID;
    Colour colour;

public:

    Vertex(unsigned int id);

    void addEdge(Vertex *vertex, unsigned value);

    unsigned long getDegree();

    Colour getColour() const;

    void setColour(Colour colour);

    void setConnectedComponentID(unsigned int connectedComponentID);

    Vertex* getNeighbour(unsigned index);

    unsigned int getConnectedComponentID() const;

    unsigned int getId() const;

};

#endif //AAL_VERTEX_H
