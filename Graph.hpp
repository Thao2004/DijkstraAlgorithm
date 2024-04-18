#ifndef GRAPH_H
#define GRAPH_H

#include "GraphBase.hpp"

class Graph : GraphBase {
public:
    Graph() {}
    ~Graph();

    virtual void addVertex(std::string label) override;
    virtual void removeVertex(std::string label) override;
    virtual void addEdge(std::string label1, std::string label2, unsigned long weight) override;
    virtual void removeEdge(std::string label1, std::string label2) override;
    virtual unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) override;

    void printGraph();

};

#endif
