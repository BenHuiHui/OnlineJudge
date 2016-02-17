//
//  P235_LowestCommonAncestorOfABinarySearchTree.cpp
//  LeetCode-Template
//
//  Created by Hui Hui on 17/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include "leetcode_util/TreeNode.cpp"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return root;
        }
        
        if (root == p) {
            return root;
        }
        
        if (root == q) {
            return root;
        }
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if (left!=nullptr && right!=nullptr) {
            return root;
        }
        
        if (left != nullptr) {
            return left;
        }
        
        if (right!=nullptr) {
            return right;
        }
        
        return nullptr;
    }
};
