package leetcode;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * Created by huihui on 9/2/16.
 */
public class P239_SlidingWindowMaximum {

    public int[] maxSlidingWindow(int[] nums, int k) {

        if (nums.length <= 0) return new int[0];

        int[] maxWindow = new int[nums.length - k + 1];
        Deque<Integer> maxDeq = new LinkedList<Integer>();

        //Preparing step
        for (int i = 0; i < k; i++) {

            while (maxDeq.size() >0 && maxDeq.peekLast() < nums[i])
                maxDeq.pollLast();

            maxDeq.addLast(nums[i]);
        }


        maxWindow[0] = maxDeq.peekFirst();

        for (int i = k; i < nums.length; i++) {

            //Deletion
            if (maxDeq.peekFirst() == nums[i-k])
                maxDeq.pollFirst();

            //Insert
            while (maxDeq.size() >0 && maxDeq.peekLast() < nums[i])
                maxDeq.pollLast();

            maxDeq.addLast(nums[i]);

            maxWindow[i-k+1] = maxDeq.peekFirst();
        }

        return maxWindow;
    }

    public static void main(String[] args){

        /*

        3 8 1 3 -1 -3 5 3 6 7

         */

        Scanner in = new Scanner(System.in);

        int k = in.nextInt();
        int n = in.nextInt();
        int[] nums = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = in.nextInt();
        }

        P239_SlidingWindowMaximum p = new P239_SlidingWindowMaximum();
        int[] results = p.maxSlidingWindow(nums, k);

        for (int i = 0; i < results.length; i++) {
            System.out.print(results[i] + " ");
        }

    }

}
