//
// Created by adam on 07.12.18.
//

#ifndef AAL_VERTEX_H
#define AAL_VERTEX_H

#include <vector>

class Vertex;

typedef std::pair<Vertex* , unsigned> vuPair; //connected vertex and value of edge

class Vertex {
    unsigned id;
    std::vector<vuPair> connectedVertex;

    unsigned connectedComponentID;

public:
    Vertex(unsigned int id);

    void addEdge (Vertex* vertex, unsigned value);

    unsigned getDegree(){
        return connectedVertex.size();
    }

};

#endif //AAL_VERTEX_H
