#include "Data Structures used/GraphNode.h"
#include <deque>
#include <set>
#include <iostream>
using std::deque;
using std::set;
// Assumes graph nodes have unique values only
GraphNode* BreadthFirstSearch(GraphNode* node, int val, set<int> visited = {}){ // Presuming its a binary tree, so no binary search tree property
    deque<GraphNode*> queue = {node}; // Queue contains a (dynamic) list of GraphNode pointers
    while(queue.size() > 0){
        auto nodeToSearch = queue[0]; 
        queue.pop_front();
        if(nodeToSearch->val == val){
            return nodeToSearch; // returns address to the node you were searching for, so shouldn't give address of local variable returned error.
        }
        for(auto nodeVisit : nodeToSearch->adj){
            if(visited.find(nodeVisit->val) == visited.end()){
                visited.insert(nodeVisit->val);
            }
            else{continue;}
            queue.push_back(nodeVisit);
        }
        
    }
    return nullptr;
}   

int main(){
    GraphNode root(1);
    GraphNode node1(2);
    GraphNode node2(3);
    GraphNode node3(4);
    root.addEdge(&node1);
    node1.addEdge(&node2);
    node2.addEdge(&node3);
    auto result = BreadthFirstSearch(&root, 4);
    if(result != nullptr){
        std::cout << "Found result!" << std::endl;
    }
    else{
        std::cout << "Couldn't find result!" << std::endl;
    }
    return 0;
}
