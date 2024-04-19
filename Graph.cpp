#include "Graph.hpp"
#include <queue>
#include <limits>

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

void Graph::removeEdge(std::string label1, std::string label2) {
    if (vertices.find(label1) != vertices.end() && vertices.find(label2) != vertices.end()) {
        Vertex *v1 = vertices[label1];
        Vertex *v2 = vertices[label2];

        //using the helper function from Vertex class (removeEdge()) 
        //remove edges between v1 and v2; vice versa
        v1->removeEdge(v2);
        v2->removeEdge(v1);
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

// Implement Dijkstra's Algorithm
/* 
        Dijkstra's Algorithm:
        
        Step 1: Initialize data structures
        Step 2: Initialize distances
        Step 3: Create a priority queue to track vertices with minimum distance
        Step 4: Update distances of adjacent vertices
        Step 5: Mark the current vertex as visited and repeat Step 4
        Step 6: Construct the shortest path using predecessors
 */
unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) {

    // Step 1: Initialize data structures

    //map to store distances from start vertex
    std::unordered_map<std::string, unsigned long> distances;

    //map to track visited vertices
    std::unordered_map<std::string, bool> visited;

    //map to store predecessors for path reconstruction
    std::unordered_map<std::string, std::string> predecessors;

    // Step 2: Initialize distances

    //initialize distances to infinity and mark all vertices as unvisited
    for (const auto& pair : vertices) {
        distances[pair.first] = std::numeric_limits<unsigned long>::max();
        visited[pair.first] = false;
    }
    distances[startLabel] = 0;

    // Step 3: Create a priority queue to track vertices with minimum distance

    /*
        The priority queue is used to keep track of the vertices with their corresponding distances,
        where the vertices with smaller distances are given higher priority.
    */      
    std::priority_queue<std::pair<unsigned long, std::string>, 
                        std::vector<std::pair<unsigned long, std::string> >, 
                        std::greater<std::pair<unsigned long, std::string> > > pq;

    pq.push(std::make_pair(0, startLabel));

    // Step 4: Update distances of adjacent vertices
    while (!pq.empty()) {
        // Pop the vertex with the smallest distance from the priority queue
        std::string current = pq.top().second;
        pq.pop();

        // Step 5: Mark the current vertex as visited
        if (visited[current]) continue;
        visited[current] = true;

        // Step 4 (continued): Update distances for neighboring vertices
        /*
        Iterate through the edges of the current vertex to access its neighboring vertices.
        For each neighboring vertex, retrieve its label and the weight of the edge connecting it to the current vertex.
        Check if the neighboring vertex has not been visited yet and if updating its distance via the current vertex
        leads to a shorter path compared to the previously recorded distance.
        If so, update the distance of the neighboring vertex to the new shorter distance.
        Also, push the updated distance and vertex label onto the priority queue to ensure that the algorithm continues
        exploring vertices with the smallest distances first.
        Additionally, update the predecessor map to keep track of the previous vertex on the shortest path to each vertex.
        */
        for (const auto& neighbor : vertices[current]->getEdges()) {
            std::string neighborLabel = neighbor.first->getLabel();
            unsigned long weight = neighbor.second;
            if (!visited[neighborLabel] && distances[current] + weight < distances[neighborLabel]) {
                // Update distance and push the updated distance and vertex label onto the priority queue
                distances[neighborLabel] = distances[current] + weight;
                pq.push(std::make_pair(distances[neighborLabel], neighborLabel));
                // Update predecessor for path reconstruction
                predecessors[neighborLabel] = current;
            }
        }
    }

    // Step 6: Construct the shortest path using predecessors
    path.clear();
    std::string currentLabel = endLabel;
    while (currentLabel != startLabel) {
        path.push_back(currentLabel);
        currentLabel = predecessors[currentLabel];
    }
    path.push_back(startLabel);
    std::reverse(path.begin(), path.end());

    // Return the shortest path length
    return distances[endLabel];
}


void Graph::printShortestPath(const std::vector<std::string>& path, unsigned long shortestDistance) {
    if (path.empty()) {
        std::cout << "No path found." << std::endl;
        return;
    }

    std::cout << "Shortest path: ";
    for (const auto& vertex : path) {
        std::cout << vertex << " ";
    }
    std::cout << "\nShortest path length: " << shortestDistance << std::endl;
}
