#include "Data Structures used/GraphNode.h"
#include "Data Structures used/TreeNode.h"
#include <deque>
#include <set>
#include <iostream>
#include <algorithm>
using std::deque;
using std::set;
using std::vector;
// BFS for binary tree
TreeNode* BreadthFirstSearchTree(TreeNode* node, int val){ // Presuming its a binary tree, so no binary search tree property
    deque<TreeNode*> queue = {node}; // Queue contains a (dynamic) list of TreeNode pointers
    while(queue.size() > 0){
        auto nodeToSearch = queue[0]; 
        queue.pop_front();
        if(nodeToSearch->val == val){
            return nodeToSearch; // returns address to the node you were searching for, so shouldn't give address of local variable returned error.
        }
        if(nodeToSearch->left){
            queue.push_back(nodeToSearch->left);
        }
        else if(nodeToSearch->right){
            queue.push_back(nodeToSearch->right);
        }
        
    }
    return nullptr;
}   
// BFS for a graph
// Assumes graph nodes have unique values only
GraphNode* BreadthFirstSearchGraph(GraphNode* node, int val, set<int> visited = {}){ // Presuming its a binary tree, so no binary search tree property
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
                queue.push_back(nodeVisit);
            }
            else{continue;}
            
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
    auto result = BreadthFirstSearchGraph(&root, 4);
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
    auto result2 = BreadthFirstSearchTree(&root2, 10);
    if(result2 != nullptr){
        std::cout << "Found result!" << std::endl;
    }
    else{
        std::cout << "Couldn't find result!" << std::endl;
    }
    return 0;
}
