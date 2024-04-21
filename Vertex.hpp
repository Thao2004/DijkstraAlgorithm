#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <unordered_map>

class Vertex {
public:
    Vertex(std::string label) : label(label) {} //constructor to initialize vertex with label
    void addEdge(Vertex* vertex, unsigned long weight) { edges[vertex] = weight; } //function to add an edge to the vertex
    void removeEdge(Vertex* vertex) { edges.erase(vertex); } //function to remove the edge from the vertex
    const std::string& getLabel() const { return label; } //return the label of the vertex
    const std::unordered_map<Vertex*, unsigned long>& getEdges() const { return edges; } //return the incident edges on the vertex

private:
    std::string label;
    std::unordered_map<Vertex*, unsigned long> edges; //map op neighbor vertices and weights
};

#endif
