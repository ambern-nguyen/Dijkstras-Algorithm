#ifndef EDGE_HPP
#define EDGE_HPP

// Edge class that stores edge weight and connecting vertex
class Edge {
public:
    int dest;
    int weight;
    Edge(int dest, int weight);
};

#endif // EDGE_HPP
