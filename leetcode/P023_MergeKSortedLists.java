package leetcode;

import java.util.ArrayList;
import java.util.Hashtable;
import java.util.PriorityQueue;

/**
 * Created by huihui on 29/1/16.
 */

public class P023_MergeKSortedLists {

    public ListNode mergeKLists(ListNode[] lists) {
        ListNode result = null;
        ListNode temp = null;

        PriorityQueue<Integer> minPQ = new PriorityQueue<Integer>();
        //Hashtable<Integer, ArrayList<ListNode>> map = new Hashtable<Integer, ArrayList<ListNode>>();

        Hashtable<Integer, ArrayList<Integer>> indexMap = new Hashtable<Integer, ArrayList<Integer>>();

        for (int i=0; i<lists.length; i++){

            if (lists[i] == null) continue;

            int val = lists[i].val;
            minPQ.add(val);

            /*
            ArrayList<ListNode> cache = map.get(val);
            if (cache == null)
                cache = new ArrayList<ListNode>();
            cache.add(lists[i]);
            map.put(val, cache);
            */

            ArrayList<Integer> index = indexMap.get(val);
            if (index == null)
                index = new ArrayList<Integer>();
            index.add(i);
            indexMap.put(val, index);
        }


        //Process the lists
        while (minPQ.size() > 0){
            int min = minPQ.poll();

            ArrayList<Integer> indexes = indexMap.get(min);
            indexMap.remove(min);

            if (indexes != null){
                for (int m=0; m<indexes.size(); m++){

                    int i = indexes.get(m);

                    if (lists[i] == null) continue;

                    //Create result array
                    if (temp == null){
                        result = temp = lists[i];
                    }
                    else{
                        temp.next = lists[i];
                        temp = temp.next;
                    }

                    //Add in new entries
                    lists[i] = lists[i].next;

                    if (lists[i] != null) {

                        minPQ.add(lists[i].val);

                        int val = lists[i].val;
                        ArrayList<Integer> index = indexMap.get(val);
                        if (index == null)
                            index = new ArrayList<Integer>();
                        index.add(i);
                        indexMap.put(val, index);
                    }
                    temp.next = null;
                }
            }
        }


        return result;
    }

    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

}
