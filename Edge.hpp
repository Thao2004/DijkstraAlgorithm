#ifndef EDGE_H
#define EDGE_H

#include "Vertex.hpp" 

class Edge {
public: 
    Edge(Vertex* v1, Vertex* v2, unsigned long weight);

private:
    Vertex* vertex1;
    Vertex* vertex2;
    unsigned long weight;
};


#endif
