import java.util.List;

/**
 * Created by huihui on 27/2/16.
 */
public class P148_SortLists {

    public ListNode sortList(ListNode head) {

        //Break -- More than 2 elements
        ListNode left = null;
        ListNode right = null;

        if (head!=null && head.next != null) {
            ListNode slow = head;
            ListNode fast = head.next;

            while (fast.next != null && fast.next.next != null){
                fast = fast.next.next;
                slow = slow.next;
            }

            left = head;
            right = slow.next;
            slow.next = null;
        }
        else{
            return head;
        }

        left = sortList(left);
        right = sortList(right);

        //Merge
        return mergeList(left, right);
    }

    public ListNode mergeList(ListNode node1, ListNode node2){

        ListNode temp = null;
        ListNode head = null;

        while (node1 != null && node2 != null){

            if (node1.val < node2.val){

                if (head == null)
                    temp = head = node1;
                else {
                    temp.next = node1;
                    temp = temp.next;
                }

                node1 = node1.next;
                temp.next = null;
            }

            else{
                if (head == null)
                    temp = head = node2;
                else {
                    temp.next = node2;
                    temp = temp.next;
                }

                node2 = node2.next;
                temp.next = null;
            }
        }

        if (node1 != null)
            temp.next = node1;

        if (node2 != null)
            temp.next = node2;

        return head;
    }

}
