package leetcode;

import leetcode.leetcode_util.ListNode;

/**
 * Created by huihui on 3/2/16.
 */

//Error null pointer exception line 53 : input empty

public class P328_OddEvenLinkedList {

    public ListNode oddEvenList(ListNode head) {

        ListNode temp = head;

        ListNode evenHead = null;
        ListNode oddHead = null;

        ListNode evenTemp = null;
        ListNode oddTemp = null;

        boolean isEven = true;

        while (temp != null){

            if (isEven){
                if (evenTemp == null){
                    evenHead = evenTemp = temp;

                }
                else{
                    evenTemp.next = temp;
                    evenTemp = evenTemp.next;
                }

                temp = temp.next;
                evenTemp.next = null;
            }

            else {

                if (oddTemp == null)
                    oddHead = oddTemp = temp;
                else{
                    oddTemp.next = temp;
                    oddTemp = oddTemp.next;
                }

                temp = temp.next;
                oddTemp.next = null;
            }

            isEven = !isEven;
        }


        evenTemp.next = oddHead;
        return evenHead;

    }

}
