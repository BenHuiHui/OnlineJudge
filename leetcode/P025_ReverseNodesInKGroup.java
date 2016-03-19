/**
 * Created by huihui on 19/3/16.
 */
public class P025_ReverseNodesInKGroup {

    public ListNode reverseKGroup(ListNode head, int k) {

        //Result
        ListNode resultsHead = null;
        ListNode resultsTmp = null;

        //Intermediate reversed
        ListNode reversedHead = null;

        //Tracing
        ListNode prev = null;
        ListNode tmp = head;

        int count = 0;

        while(tmp != null){

            prev = tmp;
            tmp = tmp.next;
            count ++;

            //Enough number of nodes
            if (count == k){

                prev.next = null;

                //Reverse nodes
                while(head != null){
                    ListNode node = head;
                    head = head.next;
                    node.next = null;
                    if(reversedHead == null){
                        reversedHead = node;
                    }
                    else{
                        node.next = reversedHead;
                        reversedHead = node;
                    }
                }

                if(resultsHead == null)
                    resultsHead = resultsTmp = reversedHead;
                else
                    resultsTmp.next = reversedHead;

                while(resultsTmp.next != null)
                    resultsTmp = resultsTmp.next;

                reversedHead = null;

                head = tmp;
                prev = null;
                count = 0;
            }
        }

        if (count > 0) {

            if (resultsHead == null)
                resultsHead = head;
            else
                resultsTmp.next = head;
        }
        return resultsHead;
    }

    private ListNode linkedListFromArray(int[] arr){
        ListNode head = null;
        ListNode tmp = null;
        for (int i = 0; i < arr.length; i++) {
            if (head == null)
                head = tmp = new ListNode(arr[i]);
            else{
                tmp.next = new ListNode(arr[i]);
                tmp = tmp.next;
            }
        }
        return head;
    }

    public static void main(String[] args){

        P025_ReverseNodesInKGroup p = new P025_ReverseNodesInKGroup();
        int[] arr = {1, 2, 3, 4, 5};
        ListNode node = p.linkedListFromArray(arr);

        node = p.reverseKGroup(node, 3);

        while (node!=null) {
            System.out.println(node.val);
            node = node.next;
        }
    }

}
