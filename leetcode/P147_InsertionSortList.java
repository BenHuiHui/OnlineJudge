package leetcode;

import leetcode.leetcode_util.ListNode;

//import java.util.List;

/*
Error: 1. head null
 */
public class P147_InsertionSortList {

    public ListNode insertionSortList(ListNode head) {

        if (head == null)
            return head;

        ListNode temp = head.next;
        ListNode prev = head;

        while (temp != null){

            //Insert to front
            if (temp.val <= head.val){

                prev.next = temp.next;
                temp.next = head;
                head = temp;
                temp = prev.next;
            }

            else {

                ListNode temp_head = head.next;
                ListNode temp_head_prev = head;
                while (temp_head.val < temp.val) {
                    temp_head = temp_head.next;
                    temp_head_prev = temp_head_prev.next;
                }

                if (temp_head != temp){
                    temp_head_prev.next = temp;
                    prev.next = temp.next;
                    temp.next = temp_head;
                    temp = prev.next;
                }
                else{
                    temp = temp.next;
                    prev = prev.next;

                }

            }

        }

        return head;
    }


}
