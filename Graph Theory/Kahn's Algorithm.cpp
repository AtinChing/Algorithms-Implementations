#include "Data Structures used/GraphNode.h"
#include <iostream>
#include <set>
#include <deque>
#include <vector>
using std::set;
using namespace std;
void Kahns(vector<GraphNode*>* ordering, GraphNode* nodes[], int nodesCount){
    deque<GraphNode*> queue;
    int inwardsCount[nodesCount] = {0};
    for(int i = 0; i < nodesCount; i++){
        GraphNode* node =  nodes[i];
        for(auto nodeTo : node->adj){
            inwardsCount[nodeTo->val] += 1;
        }
    }
    for(int i = 0; i < nodesCount; i++){
        if(inwardsCount[i] == 0){
            queue.push_front(nodes[i]);
        }
    }
    while(queue.size()){
        auto curNode = queue[0];
        queue.pop_front();
        for(auto node : curNode->adj){
            inwardsCount[node->val] -= 1;
            if(inwardsCount[node->val]==0){
                queue.push_back(node);
            }
        }
        ordering->push_back(curNode);
    }
}   
int main(){
    /*
    More simple graph to test on
    GraphNode root(1);
    GraphNode node1(2);
    GraphNode node2(3);
    GraphNode node3(4);
    root.addEdge(&node1);
    node1.addEdge(&node2);
    node2.addEdge(&node3);
    */
    // More complex graph to test on
    GraphNode root(0);  // A
    GraphNode nodeB(1);  // B
    GraphNode nodeC(2);  // C
    GraphNode nodeD(3);  // D
    GraphNode nodeE(4);  // E
    GraphNode nodeF(5);  // F

    // Add edges (directed)
    root.addEdge(&nodeB); // A -> B
    root.addEdge(&nodeC); // A -> C
    nodeB.addEdge(&nodeD); // B -> D
    nodeC.addEdge(&nodeD); // C -> D
    nodeD.addEdge(&nodeE); // D -> E
    nodeE.addEdge(&nodeF); // E -> F
    int numNodes = 6;
    GraphNode* nodes[] = {&root, &nodeB, &nodeC, &nodeD, &nodeE, &nodeF};
    vector<GraphNode*> order;
    set<int> visited;
    Kahns(&order, nodes, numNodes);
    cout << "TOPOLOGICAL ORDERING:" << endl;
    for(auto node : order){
        cout << node->val << ' ';    
    }
}
