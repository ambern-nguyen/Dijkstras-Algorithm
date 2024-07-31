#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <string>

class Vertex {
public:
    std::string label; // Vertex label
    int index; // Index of vertex in graph
    Vertex(std::string label, int index);
};

#endif // VERTEX_HPP
