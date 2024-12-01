#include "GraphNode.h"
#include <iostream>
#include <set>
using std::set;
/*  THIS IMPLEMENTATION IS NOT FOR DISJOINT/UNCONNECTED GRAPHS. 
    IF A GRAPH HAS MULTIPLE COMPONENTS THEN AN ADJANCENCY LIST MUST BE USED.
*/
// Presumes graph nodes have unique values.
GraphNode* DepthFirstSearch(GraphNode* node, int val, set<int>visited = {}){
    if(visited.find(node->val) == visited.end()){
        visited.insert(node->val);
    }
    else {return nullptr;} // visited this node already so leave
    if(node->val == val){
        return node;
    }
    for(auto nodeVisit : node->adj){
        auto res = DepthFirstSearch(nodeVisit, val);
        if(res != nullptr){
            return res;
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
    auto result = DepthFirstSearch(&root, 4);
    if(result != nullptr){
        std::cout << "Found result!" << std::endl;
    }
    else{
        std::cout << "Couldn't find result!" << std::endl;
    }
    return 0;
}
