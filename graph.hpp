#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "vertex.hpp"
#include "edge.hpp"
#include "GraphBase.hpp"
#include <iostream>
#include <set>
#include <list>
#include <algorithm>
#include <string>
#include <vector>

class Graph {
    int n; // Graph size
    std::vector<Vertex*> vertices; // Tracks all vertices in graph
    std::vector<std::vector<Edge> > adjList; // Tracks all edges in graph for each vertex

private:
    int getVertexIndex(std::string label); // Returns index of vertex with given label

public:
    Graph(); // Constructor
    void addVertex(std::string label); // Adds vertex with given label to graph
    void removeVertex(std::string label); // Removes vertex with given label from graph
    void addEdge(std::string label1, std::string label2, unsigned long weight); // Adds edge between two vertices with given labels and weight
    void removeEdge(std::string label1, std::string label2); // Removes edge between two vertices with given labels
    unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string>& path); // Takes in two vertex labels and returns the shortest path and the distance between them using Dijkstra's algorithm
    ~Graph(); // Deconstructor
};

#endif // GRAPH_HPP
