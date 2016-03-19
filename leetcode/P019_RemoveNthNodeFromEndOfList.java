/**
 * Created by huihui on 19/3/16.
 */
public class P019_RemoveNthNodeFromEndOfList {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (n <= 0) return head;
        ListNode fast = head;
        for(int i=0; i<n; i++)
            fast = fast.next;
        if(fast == null)
            return head.next;
        ListNode slow = head;
        while(fast.next != null){
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;
        return head;
    }
}
