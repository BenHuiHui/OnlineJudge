//
//  P237_DeleteNodeInALinkedList.cpp
//  CppPlayground
//
//  Created by Hui Hui on 15/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include "leetcode_util/ListNode.cpp"

class Solution {
public:
    void deleteNode(ListNode* node) {
        
        while (node->next->next != nullptr) {
            node->val = node->next->val;
            node = node->next;
        }
        
        node->val = node->next->val;
        node->next = nullptr;
        
    }
};