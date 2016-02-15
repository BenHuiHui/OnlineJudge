//
//  P203_RemoveLinkedListElements.cpp
//  CppPlayground
//
//  Created by Hui Hui on 15/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>
#include "leetcode_util/ListNode.cpp"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
     
        ListNode *temp = head;
        ListNode *prev = head;
        
        while (temp != nullptr) {
            
            if (temp->val == val) {
                
                if (temp == head) {
                    prev = temp = head = head->next;
                }
                else{
                    prev->next = temp->next;
                    temp = prev->next;
                }
            }
            else{
                prev = temp;
                temp = temp->next;
            }
                
            
        }
        
        return head;
    }
};