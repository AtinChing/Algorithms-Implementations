#include "Data Structures used/GraphNode.h"
#include "Data Structures used/TreeNode.h"
#include <iostream>
#include <set>
using std::set;
// DFS for trees
TreeNode* DepthFirstSearchTree(TreeNode* node, int val){ // Presuming its a binary tree, so no binary search tree property
    if(node->val == val){ 
        return node;
    }
    if(node->left) {
        auto res = DepthFirstSearchTree(node->left, val);
        if(res) return res;
    }
    if(node->right) {
        auto res = DepthFirstSearchTree(node->right, val);
        if(res) return res;
    }
    return nullptr;
}

// DFS for graphs
/*  THIS IMPLEMENTATION IS NOT FOR DISJOINT/UNCONNECTED GRAPHS. 
    IF A GRAPH HAS MULTIPLE COMPONENTS THEN AN ADJACENCY LIST MUST BE USED.
*/
// Presumes graph nodes have unique values.
GraphNode* DepthFirstSearchGraph(GraphNode* node, int val, set<int>visited = {}){
    if(visited.find(node->val) == visited.end()){
        visited.insert(node->val);
    }
    else {return nullptr;} // visited this node already so leave
    if(node->val == val){
        return node;
    }
    for(auto nodeVisit : node->adj){
        auto res = DepthFirstSearchGraph(nodeVisit, val);
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
    auto result = DepthFirstSearchGraph(&root, 4);
    if(result != nullptr){
        std::cout << "Found result!" << std::endl;
    }
    else{
        std::cout << "Couldn't find result!" << std::endl;
    }
    TreeNode root2(1); 
    root2.left = new TreeNode(2);
    root2.right = new TreeNode(3);
    root2.left->left = new TreeNode(4);
    root2.left->right = new TreeNode(5);
    root2.right->left = new TreeNode(6);
    root2.right->right = new TreeNode(7);
    auto result2 = DepthFirstSearchTree(&root2, 10);
    if(result != nullptr){
        std::cout << "Found result!" << std::endl;
    }
    else{
        std::cout << "Couldn't find result!" << std::endl;
    }
    return 0;
}
