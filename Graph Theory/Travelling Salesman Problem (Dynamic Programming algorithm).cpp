#include "Data Structures used/WeightedGraphNode.h"
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;
vector<GraphNode*> TSP(GraphNode* nodes[], int num_nodes, GraphNode* nodeFrom, int* size, set<GraphNode*> visited = {}){
    vector<vector<vector<pair<int, int>>>> dp;
    for(int i = 0; i < num_nodes; i++){
        vector<vector<pair<int, int>>> outerrow;
        for(int j = 0; i < num_nodes; i++){
            vector<pair<int,int>> innerrow;
            for(int k = 0; i < num_nodes; i++){
                innerrow.push_back({1, k});
            }
            outerrow.push_back(innerrow);        
        }
        dp.push_back(outerrow);
    }
    
    for(int i = 0; i < num_nodes; i++){
        auto node = nodes[i];
        for(auto nodeToPair: node->adj){
            auto nodeTo = nodeToPair.first;
            auto dist = nodeToPair.second;
            
        }
    }
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

    // complete graph needed for TSP
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
    root->addEdge(D, 7);
    root->addEdge(E, 9);
    root->addEdge(F, 12);
    root->addEdge(G, 14);
    root->addEdge(H, 10);

    B->addEdge(F, 6);
    B->addEdge(G, 7);
    B->addEdge(H, 8);

    C->addEdge(E, 10);
    C->addEdge(F, 3);
    C->addEdge(H, 7);

    D->addEdge(B, 6);
    D->addEdge(C, 5);
    D->addEdge(H, 4);

    E->addEdge(B, 8);
    E->addEdge(C, 7);
    E->addEdge(F, 3);
    E->addEdge(G, 6);

    F->addEdge(B, 5);
    F->addEdge(C, 6);
    F->addEdge(G, 2);

    G->addEdge(B, 4);
    G->addEdge(E, 1);
    G->addEdge(F, 5);

    H->addEdge(B, 2);
    H->addEdge(C, 3);
    H->addEdge(D, 4);
    H->addEdge(F, 6);
    H->addEdge(G, 8);
    auto node1 = root;
    int size = 0;
    auto res = TSP(nodes, nodesCount, node1, &size);
    cout << "Nearest neighbor algorithm path:" << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i]->val << " ";
    }
    cout << endl;
    cout << "size was " << size << endl;
    return 0;
}
