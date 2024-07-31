#include "graph.hpp"
#include <iostream>
#include <vector>

int main() {
    Graph g;
    std::vector<std::string> path;

  // Test Case 1
    std::cout << "Test Case 1:" << std::endl;
    g.addVertex("1");
    g.addVertex("2");
    g.addVertex("3");
    g.addVertex("4");
    g.addEdge("1", "2", 5);
    g.addEdge("2", "3", 2);
    g.addEdge("3", "4", 3);

    unsigned long shortestPath1 = g.shortestPath("1", "4", path);
    std::cout << "Shortest Path from 1 to 4:" << std::endl;
    if (shortestPath1 > 0) {
        std::cout << "Path: ";
        for (const auto& vertex : path) {
            std::cout << vertex << " ";
        }
        std::cout << "\nDistance: " << shortestPath1 << std::endl;
    } else {
        std::cout << "No path found" << std::endl;
    }
    std::cout << std::endl;

    // Test Case 2
    std::cout << "Test Case 2:" << std::endl;
    g.addVertex("5");
    g.addEdge("1", "5", 10);
    g.addEdge("5", "4", 1);

    unsigned long shortestPath2 = g.shortestPath("1", "4", path);
    std::cout << "Shortest Path from 1 to 4:" << std::endl;
    if (shortestPath2 > 0) {
        std::cout << "Path: ";
        for (const auto& vertex : path) {
            std::cout << vertex << " ";
        }
        std::cout << "\nDistance: " << shortestPath2 << std::endl;
    } else {
        std::cout << "No path found" << std::endl;
    }
    std::cout << std::endl;

    // Test Case 3
    std::cout << "Test Case 3:" << std::endl;
    g.removeEdge("3", "4");

    unsigned long shortestPath3 = g.shortestPath("1", "4", path);
    std::cout << "Shortest Path from 1 to 4:" << std::endl;
    if (shortestPath3 > 0) {
        std::cout << "Path: ";
        for (const auto& vertex : path) {
            std::cout << vertex << " ";
        }
        std::cout << "\nDistance: " << shortestPath3 << std::endl;
    } else {
        std::cout << "No path found" << std::endl;
    }
    std::cout << std::endl;

    // Test Case 4
    std::cout << "Test Case 4:" << std::endl;
    g.addEdge("2", "4", 7);
    g.addEdge("2", "5", 1);
    g.addEdge("5", "3", 4);

    unsigned long shortestPath4 = g.shortestPath("1", "4", path);
    std::cout << "Shortest Path from 1 to 4:" << std::endl;
    if (shortestPath4 > 0) {
        std::cout << "Path: ";
        for (const auto& vertex : path) {
            std::cout << vertex << " ";
        }
        std::cout << "\nDistance: " << shortestPath4 << std::endl;
    } else {
        std::cout << "No path found" << std::endl;
    }
    std::cout << std::endl;

    Graph t;
    // Test Case 5
    std::cout << "Test Case 5:" << std::endl;
    t.addVertex("1");
    t.addVertex("2");
    t.addVertex("3");
    t.addVertex("4");
    t.addVertex("5");
    t.addVertex("6");

    t.addEdge("1", "2", 7);
    t.addEdge("1", "3", 9);
    t.addEdge("1", "6", 14);
    t.addEdge("2", "3", 10);
    t.addEdge("2", "4", 15);
    t.addEdge("3", "4", 11);
    t.addEdge("3", "6", 2);
    t.addEdge("4", "5", 6);
    t.addEdge("5", "6", 9);

    unsigned long shortestPath6 = t.shortestPath("1", "5", path);
    std::cout << "Shortest Path from 1 to 5:" << std::endl;
    if (shortestPath6 > 0) {
        std::cout << "Path: ";
        for (const auto& vertex : path) {
            std::cout << vertex << " ";
        }
        std::cout << "\nDistance: " << shortestPath6 << std::endl;
    } else {
        std::cout << "No path found" << std::endl;
    }
    std::cout << std::endl;

  return 0;
}

