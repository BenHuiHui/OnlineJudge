//
//  P206_ReverseLinkedList.cpp
//  CppPlayground
//
//  Created by Hui Hui on 15/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include "leetcode_util/ListNode.cpp"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *temp;
        
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        temp = head->next;
        ListNode *next;
        ListNode *prev = head;
        while (temp != nullptr) {
            next = temp -> next;
            temp->next = prev;
            
            if (prev == head) {
                head->next = nullptr;
            }
            prev = temp;
            temp = next;
        }
        
        return prev;
    }
};