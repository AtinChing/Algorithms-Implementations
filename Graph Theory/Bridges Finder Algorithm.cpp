#include "Data Structures used/UndirectedWeightedGraphNode.h"
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;
struct Edge{
    GraphNode* nodeA;
    GraphNode* nodeB;
    int distance;
};
void dfs(GraphNode* node, GraphNode* parent, unordered_map<int, int>& mapping, unordered_map<int, int>& id, int& curLL, set<GraphNode*>& visited, vector<Edge>& res){
        if(mapping.find(node->val) == mapping.end()){
            id[node->val] = curLL;
            mapping[node->val] = curLL;
            curLL++;
        }
        visited.insert(node);
        for(auto nodeToPair : node->adj){
            auto nodeTo = nodeToPair.first;
            auto dist = nodeToPair.second;
            if(nodeTo==parent) continue;
            if(visited.find(nodeTo) == visited.end()){ // if this node wasn't visited
                dfs(nodeTo, node, mapping, id, curLL, visited, res);
                mapping[node->val] = min(mapping[node->val], mapping[nodeTo->val]);
                if(mapping[nodeTo->val] > id[node->val]){
                    res.push_back({node, nodeTo, dist});
                }
            }
            else{
                mapping[node->val] = min(mapping[node->val], id[nodeTo->val]);
            }
        }
}
vector<Edge> BridgesFinder(GraphNode* nodes[], int num_nodes, set<GraphNode*> visited = {}){
    unordered_map<int, int> mapping; // mapping of node val to low link value
    unordered_map<int, int> id;
    int cur = 0;
    vector<Edge> bridgeList;
    for(int i =0; i < num_nodes; i++){
        dfs(nodes[i], nullptr, mapping, id, cur, visited, bridgeList);

    }
    return bridgeList;
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
    GraphNode* I = new GraphNode(8);
    GraphNode* nodes[] = {root, B, C, D, E, F, G, H, I};
    int nodesCount = sizeof(nodes)/sizeof(GraphNode*);
    root->addEdge(B, 1);  // 0 -> 1
    B->addEdge(C, 1);     // 1 -> 2
    C->addEdge(D, 1);     // 2 -> 3
    C->addEdge(F, 1);     // 2 -> 5
    C->addEdge(root, 1); // 2 to 0
    D->addEdge(E, 1);     // 3 -> 4
    F->addEdge(G, 1);     // 5 -> 6
    G->addEdge(H, 1);     // 6 -> 7
    H->addEdge(I, 1);     // 7 -> 8
    F->addEdge(I, 1);     // 5 -> 8
    auto mstEdges = BridgesFinder(nodes, nodesCount);
    cout << "Here are all the bridges found in the given graph:" << endl;
    for(int i = 0; i < mstEdges.size(); i++){
        Edge edge = mstEdges[i];
        cout << edge.nodeA->val << " TO " << edge.nodeB->val << " WITH DISTANCE " << edge.distance << endl;
    }
    return 0;
}
