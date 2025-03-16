#include "Data Structures used/WeightedGraphNode.h"
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <climits>
using namespace std;
vector<GraphNode*> BellmanFord(GraphNode* nodes[], int dist[], int dist_len, GraphNode* node_path_to_get, set<int> visited = {}){
    dist[nodes[0]->val] = 0; // dist[i] shows lowest distance to node with val i
    GraphNode* prev[dist_len] = {nullptr};
    int nodesCount = dist_len;
    int edges = 0;
    for (int i = 0; i < nodesCount; i ++){
        edges+=nodes[i]->adj.size();
    }
    for(int j = 0; j < edges-1; j ++){
        for(int i = 0; i < nodesCount; i++){
            auto curNode = nodes[i];
            for(pair<GraphNode*, int> nodePair : curNode->adj){
                auto nodeTo = nodePair.first;
                auto distToNode = nodePair.second;
                if(dist[nodeTo->val] > distToNode+dist[curNode->val]){
                    dist[nodeTo->val] = distToNode+dist[curNode->val];
                    prev[nodeTo->val] = curNode; 
                }
            }
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
    set<int> visited;
    int distance[nodesCount];
    for(int i = 0; i < nodesCount; i++){
        distance[i] = INT_MAX;
    }
    auto nodeWeWant = E; 
    auto path = BellmanFord(nodes, distance, nodesCount, nodeWeWant);
    cout << "path found from start to end node of size " << distance[nodeWeWant->val] << "." << endl;
    for(int i = 0; i < path.size(); i++){
        cout << path[i]->val << " ";
    }
    return 0;
}
