#include "Data Structures used/WeightedGraphNode.h"
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;
// This is a suboptimal but quick solution yielding algorihtm for the travelling salesman problem.
vector<GraphNode*> NearestNeighbor(GraphNode* nodes[], int num_nodes, GraphNode* nodeFrom, int* size, set<GraphNode*> visited = {}){
    auto curNode = nodeFrom;
    vector<GraphNode*> path = {};
    while(curNode){
        int smalli = -1;
        int i = 0;
        for(pair<GraphNode*, int> nodeNext: curNode->adj){
            if(smalli == -1){ 
                if(visited.find(nodeNext.first) == visited.end()){
                    smalli = i;
                }
            }
            else if(curNode->adj[smalli].second > nodeNext.second && visited.find(nodeNext.first) == visited.end()){
                smalli = i;
            }
            i++;
        }
        path.push_back(curNode);
        visited.insert(curNode);
        if(visited.size() == num_nodes){break;}
        *size += (curNode->adj)[smalli].second;
        curNode = curNode->adj[smalli].first;
    }
    return path;
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
    auto node2 = H;
    int size = 0;
    auto res = NearestNeighbor(nodes, nodesCount, node1, &size);
    cout << "Nearest neighbor algorithm path:" << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i]->val << " ";
    }
    cout << endl;
    cout << "size was " << size << endl;
    return 0;
}
