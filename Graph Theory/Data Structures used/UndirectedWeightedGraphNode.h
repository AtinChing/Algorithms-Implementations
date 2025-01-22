#include <vector>
#include <utility>
class GraphNode {
public:
    int val;  // Value or identifier for the node
    std::vector<std::pair<GraphNode*, int>> adj;  // List of adjacent nodes (neighbors)

    // Constructor to initialize the node with a value
    GraphNode(int x) : val(x) {}

    // Find the index of an edge to a neighbor with a specific weight
    int findEdgeIndex(GraphNode* neighbor, int weight) {
        for (int i = 0; i < adj.size(); i++) {
            if (adj[i].first == neighbor && adj[i].second == weight) {
                return i;
            }
        }
        return -1; // Return -1 if not found
    }

    // Add an edge to an adjacent node
    void addEdge(GraphNode* neighbor, int weight) {
        adj.push_back(std::make_pair(neighbor, weight));
    }

    // Remove an edge to a neighbor with a specific weight
    void removeEdge(GraphNode* neighbor, int weight) {
        int index = findEdgeIndex(neighbor, weight);
        if (index != -1) {  // Only erase if the edge exists
            adj.erase(adj.begin() + index);
        }
    }
};