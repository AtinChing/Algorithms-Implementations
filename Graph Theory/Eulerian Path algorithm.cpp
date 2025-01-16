#include "Data Structures used/GraphNode.h"
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <queue>
using namespace std;
vector<GraphNode*> EulerianPathFinder(GraphNode* nodes[], vector<int> dist, const int num_nodes, GraphNode* node_path_to_get){
    unordered_map<int, pair<int, int>> map; // node num, incoming nodes, outgoing nodes
    for (int i = 0; i < num_nodes; i++){
        auto node = nodes[i];
        for(auto nodeTo : node->adj){
            map[node->val].second++;
            map[nodeTo->val].first++;
        }
    }
    GraphNode* startNode;
    GraphNode* endNode;
    for(int i = 0; i < num_nodes; i++){
        if(map[i].first - map[i].second == 1){
            endNode = nodes[i];
        }
        else if(map[i].second - map[i].first == 1){
            startNode = nodes[i];
        }
    }
    // path reconstruction
    auto curNode = node_path_to_get;
    vector<GraphNode*> path;
    while(prev[curNode->val] != nullptr){
        path.insert(path.begin(), curNode);
        curNode = prev[curNode->val];
    }
    path.insert(path.begin(), curNode);
    return path;    
}

int main(){
    // Must be guarantee that the input graph has no cycles, as a DAG can't have cycles anyway.

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
    // Add the edges
    root->addEdge(B);
    root->addEdge(C);
    B->addEdge(C);
    B->addEdge(D);
    B->addEdge(E);
    C->addEdge(D);
    C->addEdge(G);
    D->addEdge(E);
    D->addEdge(G);
    D->addEdge(F);
    E->addEdge(H);
    F->addEdge(H);
    G->addEdge(H);
    vector<int> distance(nodesCount, INT_MAX);
    auto nodeWeWant = H; 
    auto path = EulerianPathFinder(nodes, distance, nodesCount, nodeWeWant);
    cout << "shortest path possible found from start to end node of size " << distance[nodeWeWant->val] << "." << endl;
    for(int i = 0; i < path.size(); i++){
        cout << path[i]->val << " ";
    }
    return 0;
}
