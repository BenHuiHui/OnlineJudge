//
//  P199_BinaryTreeRightSideView.cpp
//  CppPlayground
//
//  Created by Hui Hui on 15/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include "leetcode_util/TreeNode.cpp"

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>sln;
        
        if (root == nullptr) {
            return sln;
        }
        
        //Level order traversal
        queue<pair<TreeNode *, int>>level;
        
        level.push(pair<TreeNode *, int>(root, 0));
        
        while (level.size()>0) {
            
            pair<TreeNode *, int>node = level.front();
            level.pop();
            
            if (level.size() == 0 || level.front().second != node.second) {
                sln.push_back(node.first->val);
            }
            
            if (node.first->left != nullptr) {
                level.push(pair<TreeNode *, int>(node.first->left, node.second+1));
            }
            
            if (node.first->right != nullptr) {
                level.push(pair<TreeNode *, int>(node.first->right, node.second+1));
            }
        }
        
        return sln;
    }
    
    
    
};