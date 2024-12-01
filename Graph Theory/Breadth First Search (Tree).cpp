#include "TreeNode.h"
#include <deque>
#include <iostream>
using std::deque;
TreeNode* BreadthFirstSearch(TreeNode* node, int val){ // Presuming its a binary tree, so no binary search tree property
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

int main(){
    TreeNode root(1); 
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.left->left = new TreeNode(4);
    root.left->right = new TreeNode(5);
    root.right->left = new TreeNode(6);
    root.right->right = new TreeNode(7);
    auto result = BreadthFirstSearch(&root, 10);
    if(result != nullptr){
        std::cout << "Found result!" << std::endl;
    }
    else{
        std::cout << "Couldn't find result!" << std::endl;
    }
    return 0;
}
