#include "Graph.hpp"
#include <tuple>

int main() {

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

    // Test the removeEdge function
    /*
    graph2.addEdge("1", "5", 12);
    graph2.addEdge("2", "6", 14);
    graph2.printGraph();
    std::cout << std::endl;

    std::cout << "Testing removeEdge" << std::endl;
    graph2.removeEdge("1", "5");
    graph2.removeEdge("2", "6");
    graph2.printGraph();
    std::cout << std::endl;

    */

    
    std::cout << "Testing shortest path algorithm" << std::endl;


    std::vector<std::string> path;
    unsigned long shortestDistance = graph2.shortestPath("1", "5", path);

    graph2.printShortestPath(path, shortestDistance);

    std::cout << std::endl;


    // Create new graph
    Graph graph3;

    /* Add many vertices at once
    // Define vertices and edges
    std::vector<std::string> vertices = { "0", "1", "2", "3", "4", "5", "6", "7" };

    std::vector<std::tuple<std::string, std::string, unsigned long>> edge = {
        {"0", "1", 4}, {"0", "7", 8}, 
        {"1", "2", 8}, {"1", "7", 11},
        {"2", "3", 7}, {"2", "5", 4}, {"2", "8", 2},
        {"3", "4", 9}, {"3", "5", 14},
        {"4", "5", 10},
        {"5", "6", 2},
        {"6", "8", 6}, {"6", "7", 1},
        {"7", "8", 7}
    };

    // Add vertices
    for (const auto& vertex : vertices) {
        graph3.addVertex(vertex);
    }

    // Add edges
    for (const auto& edge : edge) {
        graph3.addEdge(std::get<0>(edge), std::get<1>(edge), std::get<2>(edge));
    }
    */

    graph3.addVertex("0");
    graph3.addVertex("1");
    graph3.addVertex("2");
    graph3.addVertex("3");
    graph3.addVertex("4");
    graph3.addVertex("5");
    graph3.addVertex("6");
    graph3.addVertex("7");

    graph3.printVertices();
    std::cout << std::endl;

    graph3.addEdge("0", "1", 4);
    graph3.addEdge("0", "7", 8);
    graph3.addEdge("1", "2", 8);
    graph3.addEdge("1", "7", 7);
    graph3.addEdge("2", "3", 7);
    graph3.addEdge("2", "5", 4);
    graph3.addEdge("2", "8", 4);
    graph3.addEdge("3", "4", 9);
    graph3.addEdge("3", "5", 14);
    graph3.addEdge("4", "5", 10);
    graph3.addEdge("5", "6", 2);
    graph3.addEdge("6", "7", 1);
    graph3.addEdge("6", "8", 6);
    graph3.addEdge("7", "8", 7);


    graph3.printGraph();
    std::cout << std::endl;

    // Test shortest path algorithm
    std::vector<std::string> path1;
    unsigned long shortestPath = graph3.shortestPath("0", "6", path1);

    std::cout << "Shortest path from vertex 0 to vertex 6:" << std::endl;
    graph3.printShortestPath(path1, shortestPath);
    
    return 0;
}