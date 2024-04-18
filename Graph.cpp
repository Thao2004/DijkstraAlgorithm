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

void Graph::addEdge(std::string label1, std::string label2, unsigned long weight) {
    //check if both the vertices exist in the graph
    if (vertices.find(label1) != vertices.end() && vertices.find(label2) != vertices.end()) {
        //retrieve pointer to the vertex using the labels
        Vertex *v1 = vertices[label1];
        Vertex *v2 = vertices[label2];

        //adding the edge between two vertices by calling the addEdge helper function of the Vertex class
        //since this is an undirected graph, the edge is added from both sides
        v1->addEdge(v2, weight);
        v2->addEdge(v1, weight);
    }
}

void Graph::printGraph() {
    for (const auto& pair : vertices) {
        //print the label of the current vertex
        std::cout << "Vertex " << pair.first << " is connected to: ";
        //get the edges of the current vertex
        const auto& edges = pair.second->getEdges();

        //iteratre over each edge of the current vertex
        for (const auto& edge : edges) {
            //print the label of the adjacent vertex and the weight
            std::cout << "(" << edge.first->getLabel() << ", weight: " << edge.second << "), ";
        }
        std::cout << std::endl;
    }
}