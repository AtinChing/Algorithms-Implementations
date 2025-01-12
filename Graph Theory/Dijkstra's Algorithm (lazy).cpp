#include "Data Structures used/WeightedGraphNode.h"
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <queue>
using namespace std;
vector<GraphNode*> Dijkstras(GraphNode* nodes[], vector<int> dist, const int num_nodes, GraphNode* node_path_to_get){
    dist[nodes[0]->val] = 0; // dist[i] shows lowest distance to node with val i
    vector<GraphNode*> prev(num_nodes, nullptr);
    vector<bool> visited(num_nodes, false);
    auto cmp = [](const pair<GraphNode*, int>& a, const pair<GraphNode*, int>& b) { // comparator function to allow node int pairs to be compared within the pq to get min-heap behaviour
        return a.second > b.second; // min-heap behaviour
    };
    priority_queue<pair<GraphNode*, int>, vector<pair<GraphNode*, int>>, decltype(cmp)> pq(cmp);
    pq.push({nodes[0], 0});
    while(!pq.empty()){
        auto [curNode, distToCurNode] = pq.top();
        pq.pop();
        visited[curNode->val] = true;
        for(auto [nodeTo, distToNode] : curNode->adj){
            if(visited[nodeTo->val]) continue; // don't visit/relax a node that you've already visited/relaxed
            if(distToNode+distToCurNode < dist[nodeTo->val]){
                int newDist = distToNode+distToCurNode;
                prev[nodeTo->val] = curNode;
                dist[nodeTo->val] = newDist;
                pq.push({nodeTo, newDist});
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
    vector<int> distance(nodesCount, INT_MAX);
    auto nodeWeWant = H; 
    auto path = Dijkstras(nodes, distance, nodesCount, nodeWeWant);
    cout << "shortest path possible found from start to end node of size " << distance[nodeWeWant->val] << "." << endl;
    for(int i = 0; i < path.size(); i++){
        cout << path[i]->val << " ";
    }
    return 0;
}
