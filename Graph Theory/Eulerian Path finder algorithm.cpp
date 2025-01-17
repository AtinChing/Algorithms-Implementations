#include "Data Structures used/GraphNodeUniqueEdge.h"
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <queue>
using namespace std;
struct Edge {
    GraphNode* nodeA;
    GraphNode* nodeB;
};
deque<GraphNode*> DFS(GraphNode* node, deque<GraphNode*>& unwind, set<int>& visited){
    for(auto nodeToPair : node->adj){
        auto nodeTo = nodeToPair.first;
        auto edgeId = nodeToPair.second;
        if (visited.find(edgeId) == visited.end()) {
            visited.insert(edgeId); 
            DFS(nodeTo, unwind, visited);
        }
    }
    unwind.push_front(node);
    
    return unwind;
}
deque<GraphNode*> EulerianPathFinder(GraphNode* nodes[], const int num_nodes){
    unordered_map<int, pair<int, int>> map; // node num, incoming nodes, outgoing nodes
    set<int> visited;
    int curid = 0;
    for (int i = 0; i < num_nodes; i++) {
        map[nodes[i]->val] = {0, 0};
    }
    for (int i = 0; i < num_nodes; i++){
        auto node = nodes[i];
        for(int j = 0; j < node->adj.size(); j++){
            auto nodeToPair = node->adj[j];
            map[node->val].second++;
            map[nodeToPair.first->val].first++;
            nodes[i]->adj[j].second = curid;
            curid++;
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
    deque<GraphNode*> stackUnwind;
    return DFS(startNode, stackUnwind, visited);
}

int main(){
    // A simple graph to test on has been given below.
    /*  
        GraphNode* root = new GraphNode(0);
        GraphNode* B = new GraphNode(1);
        GraphNode* C = new GraphNode(2);
        GraphNode* D = new GraphNode(3);
        GraphNode* E = new GraphNode(4);
        GraphNode* nodes[] = {root, B, C, D, E};
        root->addEdge(B);
        B->addEdge(C);
        B->addEdge(D);
        C->addEdge(B);
        D->addEdge(E);
    */
   // More complex graph to test on
    GraphNode* node0 = new GraphNode(0);
    GraphNode* node1 = new GraphNode(1);
    GraphNode* node2 = new GraphNode(2);
    GraphNode* node3 = new GraphNode(3);
    GraphNode* node4 = new GraphNode(4);
    GraphNode* node5 = new GraphNode(5);
    GraphNode* node6 = new GraphNode(6);
    GraphNode* nodes[] = {node0, node1, node2, node3, node4, node5, node6};

    node1->addEdge(node2);
    node1->addEdge(node3);

    node2->addEdge(node4);
    node2->addEdge(node4); 
    node2->addEdge(node2); // Self-loop

    node3->addEdge(node1);
    node3->addEdge(node5);
    node3->addEdge(node2);

    node4->addEdge(node3);
    node4->addEdge(node6);

    node5->addEdge(node6);

    node6->addEdge(node3);

    int nodesCount = sizeof(nodes)/sizeof(GraphNode*);
    auto path = EulerianPathFinder(nodes, nodesCount);
    cout << "Eulerian path found." << endl;
    for(int i = 0; i < path.size()-1; i++){
        cout << path[i]->val << " - ";
    }
    cout << path[path.size()-1]->val << endl;
    return 0;
}
