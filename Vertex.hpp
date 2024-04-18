#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <unordered_map>

class Vertex {
public:
    Vertex(std::string label) : label(label) {}
    void addEdge(Vertex* vertex, unsigned long weight);
    void removeEdge(Vertex* vertex);
    const std::string& getLabel() const;

private:
    std::string label;
};


#endif
