#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <unordered_map>

class Vertex {
public:
    Vertex(std::string label) : label(label) {}
    void addEdge(Vertex* vertex, unsigned long weight) { edges[vertex] = weight; }
    void removeEdge(Vertex* vertex) { edges.erase(vertex); }
    const std::string& getLabel() const { return label; }
    const std::unordered_map<Vertex*, unsigned long>& getEdges() const { return edges; }

private:
    std::string label;
    std::unordered_map<Vertex*, unsigned long> edges;
};

#endif
