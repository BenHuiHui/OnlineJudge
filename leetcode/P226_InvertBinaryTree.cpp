//
//  P226_InvertBinaryTree.cpp
//  CppPlayground
//
//  Created by Hui Hui on 10/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include "leetcode_util/TreeNode.cpp"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if (root == 0) {
            return 0;
        }
        
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
