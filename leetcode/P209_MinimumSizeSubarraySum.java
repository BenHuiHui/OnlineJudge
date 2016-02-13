package leetcode;

/**
 * Created by huihui on 7/2/16.
 */
public class P209_MinimumSizeSubarraySum {

    public int minSubArrayLen(int s, int[] nums) {

        int size = Integer.MAX_VALUE;
        int sum = 0;

        int low = 0;

        for (int hi = 0; hi <nums.length ; hi++) {

            sum += nums[hi];

            if (sum >= s){

                while (low < nums.length && sum - nums[low] >= s) {
                    low++;
                    sum -= nums[low-1];
                }

                if (hi - low + 1 <= size)
                    size = hi - low + 1;
            }

        }

        if (size == Integer.MAX_VALUE)
            return 0;
        return size;
    }

}
