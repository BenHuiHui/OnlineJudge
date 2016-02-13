//
//  P086_PartitionList.cpp
//  CppPlayground
//
//  Created by Hui Hui on 13/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include "leetcode_util/ListNode.cpp"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *larger = nullptr;
        ListNode *larger_temp = nullptr;
        ListNode *temp = head;
        ListNode *prev = head;
        
        while (temp != nullptr) {
            
            if (temp->val >= x) {
                
                if (larger_temp == nullptr) {
                    larger = larger_temp = temp;
                }
                else{
                    larger_temp->next = temp;
                    larger_temp = larger_temp->next;
                }
                
                if (temp == head) {
                    prev = head = temp = temp->next;
                }
                else{
                    prev->next = temp->next;
                    temp = prev->next;
                }
                
                larger_temp->next = nullptr;
            }
            
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        
        if (head == nullptr) {
            return larger;
        }
        
        prev->next = larger;
        
        return head;
    }
};