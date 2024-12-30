#include "Data Structures used/WeightedGraphNode.h"
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;
int FloydWarshall(GraphNode* nodes[], int num_nodes, GraphNode* nodeFrom, GraphNode* nodeTo){
    int k = num_nodes;
    int distance[k][k][k];
    for(int k1 = 0; k1 < k; k1++){
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                distance[k][i][j] = 10000000;
            }
            
        }
        
    }  
    for(int i = 0; i < num_nodes; i++){
        for(pair<GraphNode*, int> nodeToPair: node->adj){
            distance[node->val][nodeToPair.first->val] = nodeToPair.second; 
        }
    }
    for(int k1 = 1; k1 < k; k1++){
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                distance[k][i][j] = min(distance[k-1][i][j], dp[k-1][i][k] + dp[k-1][k][j]);
            }
            
        }
        
    }      
    return distance[nodeFrom->val][nodeTo->val];
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
    root->addEdge(B, 3);
    root->addEdge(C, 6);
    B->addEdge(C, 4);
    B->addEdge(D, 4);
    B->addEdge(E, 11);
    C->addEdge(D, 8);
    C->addEdge(B, 2);
    C->addEdge(G, 11);
    D->addEdge(E, -4);
    D->addEdge(G, 2);
    D->addEdge(F, 5);
    E->addEdge(H, 9);
    F->addEdge(H, 1);
    G->addEdge(H, 2);
    auto node1 = root;
    auto node2 = H;
    auto res = FloydWarshall(nodes, nodesCount, node1, node2);
    cout << "Shortest distance between " << node1->val << " and " << node2->val << " is " << res;
    return 0;
}
