#include "Data Structures used/WeightedGraphNode.h"
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;
struct Edge{
    GraphNode* nodeA;
    GraphNode* nodeB;
    int distance;
    bool operator<(const Edge& other) const {
        return distance < other.distance;
    }
};
vector<Edge> Prims(GraphNode* nodes[], int num_nodes, GraphNode* start, set<GraphNode*> included = {}){
    /*vector<Edge> edges;
    for(int i = 0; i < num_nodes; i++){
        auto node = nodes[i];
        for(auto pair: node->adj){
            Edge edge = {node, pair.first, pair.second};
            edges.push_back(edge);
        }
    }*/
    vector<Edge> result;
    priority_queue<Edge> edges;
    for (auto nodeToPair : start->adj){
        edges.push({start, nodeToPair.first, nodeToPair.second});
    }
    
    return result;
    // Optional code below to convert the graph into the MST (remove any edges that aren't part of the final MST set of edges)
    /*for(auto node : nodes){
        for(auto pair : node->adj){
            Edge edge = {node, pair.first, pair.second};
            if(approvedEdges.find(edge) == approvedEdges.end()){
                node->removeEdge(pair.first, pair.second);
            }
        }
    }*/
}

int main(){
    GraphNode* root = new GraphNode(0);
    GraphNode* B = new GraphNode(1);
    GraphNode* C = new GraphNode(2);
    GraphNode* D = new GraphNode(3);
    GraphNode* E = new GraphNode(4);
    GraphNode* F = new GraphNode(5);
    GraphNode* G = new GraphNode(6);
    GraphNode* H = new GraphNode(7);
    GraphNode* nodes[] = {root, B, C, D, E, F, G, H};
    int nodesCount = sizeof(nodes)/sizeof(GraphNode*);
    root->addEdge(B, 3);
    root->addEdge(C, 6);
    B->addEdge(C, 4);
    B->addEdge(D, 4);
    B->addEdge(E, 11);
    C->addEdge(D, 8);
    C->addEdge(G, 11);
    D->addEdge(E, -4);
    D->addEdge(G, 2);
    D->addEdge(F, 5);
    E->addEdge(H, 9);
    F->addEdge(H, 1);
    G->addEdge(H, 2);
    auto mstEdges = Prims(nodes, nodesCount, root);
    cout << "Found an MST that contains the following edges:" << endl;
    for(int i = 0; i < mstEdges.size(); i++){
        Edge edge = mstEdges[i];
        cout << edge.nodeA->val << " TO " << edge.nodeB->val << " WITH DISTANCE " << edge.distance << endl;
    }
    return 0;
}
