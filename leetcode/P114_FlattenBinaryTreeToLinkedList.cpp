//
//  P114_FlattenBinaryTreeToLinkedList.cpp
//  CppPlayground
//
//  Created by Hui Hui on 13/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include "leetcode_util/TreeNode.cpp"

class Solution {
public:
    void flatten(TreeNode* root) {
        root = flat(root);
    }
    
    TreeNode* flat(TreeNode *node){
        
        if (node == nullptr) {
            return node;
        }
        
        if (node->left == nullptr && node->right == nullptr) {
            return node;
        }
        
        TreeNode *left = flat(node->left);
        
        if (left == nullptr) {
            node -> right = flat(node->right);
        }
        else{
            TreeNode *temp = left;
            while (temp->right != nullptr) {
                temp = temp->right;
            }
            temp->right = flat(node->right);
            node->right = left;
            node->left = nullptr;
        }
        
        return node;
    }
    
};