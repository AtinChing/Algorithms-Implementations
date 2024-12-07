#include "Data Structures used/WeightedGraphNode.h"
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <deque>
using namespace std;
void TopSort(GraphNode* node, vector<GraphNode*>* ordering, set<int> *visited){
    for(auto nodeVisit : node->adj){
        if(visited->find(nodeVisit.first->val) == visited->end()){
            visited->insert(nodeVisit.first->val);
            TopSort(nodeVisit.first, ordering, visited);
        }
    }
    ordering->insert(ordering->begin(), node);
}   
vector<GraphNode*> ShortestPathDAG(vector<GraphNode*> ordering, int dist[], int dist_len, set<int> visited = {}){
    dist[ordering[0]->val] = 0; // dist[i] shows lowest distance to node with val i
    deque<GraphNode*> queue = {ordering[0]};
    GraphNode* prev[dist_len] = {nullptr};
    while(queue.size() > 0){
        auto curNode = queue[0];
        queue.pop_front();
        for(pair<GraphNode*, int> nodePair : curNode->adj){
            auto nodeTo = nodePair.first;
            auto distToNode = nodePair.second;
            if(dist[nodeTo->val] > distToNode){
                dist[nodeTo->val] = distToNode;
                queue.push_back(nodeTo);
                prev[nodeTo->val] = curNode; 
            }
        }
    }
    // path reconstruction
    auto curNode = ordering[dist_len-1];
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
    vector<GraphNode*> order;
    int distance[order.size()];
    for(int i = 0; i < order.size(); i++){
        distance[i] = __INT_MAX__;
    }
    set<int> visited;
    TopSort(root, &order, &visited);
    auto path = ShortestPathDAG(order, distance, order.size());
    cout << endl;
    cout << "path found from start to end node." << endl;
    for(int i = 0; i < order.size(); i++){
        cout << path[i]->val << " ";
    }
    return 0;
}
