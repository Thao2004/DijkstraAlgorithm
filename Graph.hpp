#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <iostream>

#include "GraphBase.hpp"
#include "Vertex.hpp"

class Graph : GraphBase {
public:
    Graph() {} //constructor
    //~Graph(); //destructor

    virtual void addVertex(std::string label) override;
    virtual void removeVertex(std::string label) override;
    //virtual void addEdge(std::string label1, std::string label2, unsigned long weight) override;
    //virtual void removeEdge(std::string label1, std::string label2) override;
    //virtual unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) override;

    void printGraph();
    void printVertices(); //print all the vertices in the graph


private: 
    //storing the vertices of the graph
    std::unordered_map<std::string, Vertex*> vertices;
};

#endif
