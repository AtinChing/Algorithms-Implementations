#include <vector> 

class GraphNode {
public:
    int val;  // Value or identifier for the node
    std::vector<GraphNode*> adj;  // List of adjacent nodes (neighbors)

    // Constructor to initialize the node with a value
    GraphNode(int x) : val(x) {}

    // Add an undirected edge to an adjacent node
    void addEdge(GraphNode* neighbor) {
        adj.push_back(neighbor);
        neighbor->adj.push_back(this);  // Add this node to the neighbor's adjacency list
    }
};