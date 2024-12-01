#include "Data Structures used/TreeNode.h"
#include <iostream>
TreeNode* DepthFirstSearch(TreeNode* node, int val){ // Presuming its a binary tree, so no binary search tree property
    if(node->val == val){ 
        return node;
    }
    if(node->left) {
        auto res = DepthFirstSearch(node->left, val);
        if(res) return res;
    }
    if(node->right) {
        auto res = DepthFirstSearch(node->right, val);
        if(res) return res;
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
    auto result = DepthFirstSearch(&root, 10);
    if(result != nullptr){
        std::cout << "Found result!" << std::endl;
    }
    else{
        std::cout << "Couldn't find result!" << std::endl;
    }
    return 0;
}
