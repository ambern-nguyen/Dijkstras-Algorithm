#include "graph.hpp"

Graph::Graph() {
    n = 0;
}

// Searches through the vertices vector to find the vertex with the given label
int Graph::getVertexIndex(std::string label) {
    for(int i = 0; i < vertices.size(); ++i) {
        if(vertices[i]->label == label) {
            return i;
        }
    }
    return -1;
}

// Adds a vertex to the graph with the given label if the vertex does not currently exist in the graph
void Graph::addVertex(std::string label) {
    if(getVertexIndex(label) == -1) {
        Vertex* newVertex = new Vertex(label, n);
        vertices.push_back(newVertex);
        adjList.push_back(std::vector<Edge>());
        n++;
    }
}

// Removes a vertex with the given label from the graph if it exists
// Deletes all connecting edges
void Graph::removeVertex(std::string label) {
    int index = getVertexIndex(label);
    if(index != -1) {
        vertices.erase(vertices.begin() + index);
        adjList.erase(adjList.begin() + index);
        for(std::vector<Edge>& edges : adjList) {
            for(auto it = edges.begin(); it != edges.end();) {
                if(it->dest == index) {
                    it = edges.erase(it);
                } else {
                    if(it->dest > index) {
                        it->dest--;
                    }
                    ++it;
                }
            }
        }
        n--;
    }
}

// Creates an edge between two vertices with the given labels and weight
void Graph::addEdge(std::string label1, std::string label2, unsigned long weight) {
    int index1 = getVertexIndex(label1);
    int index2 = getVertexIndex(label2);
    if(index1 != -1 && index2 != -1 && index1 != index2) {
        for(const Edge& edge : adjList[index1]) {
            if(edge.dest == index2) {
                return; // Edge already exists
            }
        }
        // Add edge to both vertices since edges are undirected
        adjList[index1].push_back(Edge(index2, weight));
        adjList[index2].push_back(Edge(index1, weight));
    }
}

// Removes an edge from between two vertices with the given labels if it exists
void Graph::removeEdge(std::string label1, std::string label2) {
    int index1 = getVertexIndex(label1);
    int index2 = getVertexIndex(label2);
    if(index1 != -1 && index2 != -1) {
        // Remove edge from index1 to index2
        for(auto it = adjList[index1].begin(); it != adjList[index1].end(); ++it) {
            if(it->dest == index2) {
                adjList[index1].erase(it);
                break;
            }
        }
        // Remove edge going in opposite direction
        for(auto it = adjList[index2].begin(); it != adjList[index2].end(); ++it) {
            if(it->dest == index1) {
                adjList[index2].erase(it);
                break;
            }
        }
    }
}

// Takes in two vertex labels and returns the shortest path and the distance between them using Dijkstra's algorithm
unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string>& path) {
    int start;
    int end;

    // Makes the starting vertex whichever vertex has the smaller label
    if (std::stoi(startLabel) < std::stoi(endLabel)){
      start = getVertexIndex(startLabel);
      end = getVertexIndex(endLabel);
    }
    else{
      end = getVertexIndex(startLabel);
      start = getVertexIndex(endLabel);
    }

    // If the starting vertex or ending vertex is not in the graph, return 0
    if(start == -1 || end == -1) {
        std::cerr << "Start or end vertex not found!\n";
        return 0;
    }

    /* Creates a vector to track the distance between the source vertex and all
    other vertices. Initially sets all distances to 9999 (represents infinity in our
    case)*/
    // Creates a vector to track the previous vertex in the shortest path. Will be used to return shortest path later
    std::vector<int> dist(n, 9999);
    std::vector<int> prev(n, -1);
    std::set<int> S; // Set of visited vertices
    std::list<int> Q; // Unvisited vertices
  
    // Sets the distance of the starting vertex to 0 and adds all vertices to list of unvisited vertices
    dist[start] = 0;
    for(int u = 0; u < n; u++) {
        Q.push_back(u);
    }

  // Dijkstra's algorithm
    while(!Q.empty()) {
        auto i = min_element(Q.begin(), Q.end()); // Find the smallest element in the list of unvisited vertices
        int u = *i;
        Q.remove(u); // Takes vertex out of unvisited vertices
        S.insert(u); // Adds to visited vertices

      // Updates distances and previous vertices in path
        for(const Edge& edge : adjList[u]) {  
            if((dist[u] + edge.weight) < dist[edge.dest]) {
                dist[edge.dest] = dist[u] + edge.weight;
                prev[edge.dest] = u;
            }
        }
    }

    // Reconstruct shortest path in path vector
    path.clear();
    int curr = end;
    while(curr != -1) {
        path.insert(path.begin(), vertices[curr]->label);
        curr = prev[curr];
    }

    // If the end vertex is smaller than the start vertex, reverse the path
    if (std::stoi(endLabel) < std::stoi(startLabel)){
      reverse(path.begin(), path.end());
    }
  
    // Return the distance between the start and end vertex
    return dist[end];
}

//Deconstructor
Graph::~Graph() {
    for(Vertex* vertex : vertices) {
        delete vertex;
    }
}
