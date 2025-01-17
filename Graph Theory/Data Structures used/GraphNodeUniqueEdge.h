#include <vector>
class GraphNode {
public:
    int val;  // Value or identifier for the node
    std::vector<std::pair<GraphNode*, int>> adj;  // List of adjacent nodes (neighbors)
    int curid = 0;
    // Constructor to initialize the node with a value
    GraphNode(int x) : val(x) {}

    // Add an edge to an adjacent node
    void addEdge(GraphNode* neighbor) {
        adj.push_back({neighbor, 0});
    }
};
