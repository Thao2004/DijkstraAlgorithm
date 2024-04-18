#include "Graph.hpp"

void Graph::addVertex(std::string label) {
    //check whether the label of the vertex already existed
    if (vertices.find(label) == vertices.end()) {
        vertices[label] = new Vertex(label);
    }
}

void Graph::removeVertex(std::string label) {
    //return an iterator to the vertex with the matching label
    auto iterator = vertices.find(label);

    //check if the vertex with the given label exists in the graph
    if (iterator != vertices.end()) {
        //iterate over the adjacent vertices of the vertex to be removed
        for (auto& pair: iterator->second->getEdges()) {
            //remove the edge between ajacent vertices and vertex
            pair.first->removeEdge(iterator->second);
        }
        //delete the vertex object
        delete iterator->second;
        //remove the vertex from the map
        vertices.erase(iterator);
    }
}

void Graph::printVertices() {
    std::cout << "Vertices in the graph: " << std::endl;
    for (const auto& pair : vertices) {
        std::cout << pair.first << std::endl;
    }
}
