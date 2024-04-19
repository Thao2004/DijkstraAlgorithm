#include "Graph.hpp"

int main() {
    /*
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
    */
    

    Graph graph2;

    graph2.addVertex("1");
    graph2.addVertex("2");
    graph2.addVertex("3");
    graph2.addVertex("4");
    graph2.addVertex("5");
    graph2.addVertex("6");

    graph2.printVertices();
    std::cout << std::endl;

    graph2.addEdge("1", "2", 7);
    graph2.addEdge("1", "3", 9);
    graph2.addEdge("1", "6", 14);
    graph2.addEdge("2", "3", 10);
    graph2.addEdge("2", "4", 15);
    graph2.addEdge("3", "4", 11);
    graph2.addEdge("3", "4", 11);
    graph2.addEdge("3", "6", 2);
    graph2.addEdge("4", "5", 6);
    graph2.addEdge("5", "6", 9);

    graph2.printGraph();
    std::cout << std::endl;

    graph2.addEdge("1", "5", 12);
    graph2.addEdge("2", "6", 14);
    graph2.printGraph();
    std::cout << std::endl;

    std::cout << "Testing removeEdge" << std::endl;
    graph2.removeEdge("1", "5");
    graph2.removeEdge("2", "6");
    graph2.printGraph();
    std::cout << std::endl;

    std::cout << "Testing shortest path algorithm" << std::endl;


    std::vector<std::string> path;
    unsigned long shortestDistance = graph2.shortestPath("1", "5", path);

    graph2.printShortestPath(path, shortestDistance);
    
    return 0;
}