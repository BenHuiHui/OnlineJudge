package leetcode;

import java.util.Collections;
import java.util.PriorityQueue;

/**
 * Created by huihui on 7/2/16.
 */
public class P295_FindMedianFromDataStream {


    PriorityQueue<Integer> minPQ;
    PriorityQueue<Integer> maxPQ;

    public void addNum(int num) {

        if (minPQ == null)
            minPQ = new PriorityQueue<Integer>();

        if (maxPQ == null)
            maxPQ = new PriorityQueue<Integer>(1, Collections.<Integer>reverseOrder());

        /*
        if (minPQ.size() == maxPQ.size())
            minPQ.add(num);

        else if (minPQ.size() == maxPQ.size() +1 ){
            minPQ.add(num);
            maxPQ.add(minPQ.poll());
        }
        */

        if (minPQ.size() == 0)
            minPQ.add(num);
        else {
            if (num >= minPQ.peek()) {
                minPQ.add(num);
            } else
                maxPQ.add(num);

            if (minPQ.size() == maxPQ.size() + 2)
                maxPQ.add(minPQ.poll());
            else if (minPQ.size() == maxPQ.size() - 1)
                minPQ.add(maxPQ.poll());
        }
    }

    // Returns the median of current data stream
    public double findMedian() {

        if (maxPQ == null)
            return minPQ.peek();

        if (minPQ.size() == maxPQ.size()){
            return (minPQ.peek() + maxPQ.peek()) * 0.5;
        }
        else
            return minPQ.peek();

    }

    public static void main(String[] args){
        P295_FindMedianFromDataStream p = new P295_FindMedianFromDataStream();

        /*
        p.addNum(-1);
        System.out.println(p.findMedian());
        p.addNum(-2);
        System.out.println(p.findMedian());
        p.addNum(-3);
        System.out.println(p.findMedian());
        */

        p.addNum(2);
        System.out.println(p.findMedian());
        p.addNum(3);
        System.out.println(p.findMedian());
    }


}
