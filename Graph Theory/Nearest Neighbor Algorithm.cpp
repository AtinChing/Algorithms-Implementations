#include "Data Structures used/WeightedGraphNode.h"
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;
vector<GraphNode*> NearestNeighbor(GraphNode* nodes[], int num_nodes, GraphNode* nodeFrom, GraphNode* nodeTo, int* size, set<int> visited = {}){
    auto curNode = nodeFrom;
    vector<GraphNode*> path = {};
    while(curNode){
        int smalli = 0;
        int i = 0;
        for(pair<GraphNode*, int> nodeNext: curNode->adj){
            if(curNode->adj[smalli].second > nodeNext.second && visited.find(curNode) == visited.end()){
                smalli = i;
            }
            i++;
        }
        path.push_back(curNode);
        visited.insert(curNode);
        curNode = curNode->adj[smalli].first;
        *size += curNode->adj[smalli].second;
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
    int size = 0;
    auto res = NearestNeighbor(nodes, nodesCount, node1, node2, &size);
    cout << "Nearest neighbor algorithm path:" << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i]->val << " ";
    }
    cout << endl;
    cout << "size was " << size << endl;
    return 0;
}
