//
//  P098_ValidateBinarySearchTree.cpp
//  CppPlayground
//
//  Created by Hui Hui on 16/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>
#include <climits>

#include "leetcode_util/TreeNode.cpp"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX, false, false);
    }
    
    bool isValidBST(TreeNode *node, int min, int max, bool left, bool right){
        
        if (node == nullptr) {
            return true;
        }
        
        return ((node->val < max || !right)&& (node -> val > min || !left) && isValidBST(node->left, min, node->val, left, true) && isValidBST(node->right, node->val, max, true, right));
        
    }
};