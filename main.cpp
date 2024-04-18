#include "Graph.hpp"

int main() {
    Graph graph1;

    //add vertex
    graph1.addVertex("A");
    graph1.addVertex("B");
    graph1.addVertex("C");

    graph1.printVertices();
    std::cout << std::endl;

    graph1.addEdge("A", "B", 2);
    graph1.addEdge("A", "C", 3);

    graph1.printGraph();
    std::cout << std::endl;

    Graph graph2;

    graph2.addVertex("1");
    graph2.addVertex("2");
    graph2.addVertex("3");

    graph2.printVertices();




    return 0;
}