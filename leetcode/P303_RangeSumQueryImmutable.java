/**
 * Created by huihui on 29/2/16.
 */
public class NumArray {

    int[] csum;

    public NumArray(int[] nums) {
        csum = new int[nums.length];
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            csum[i] = sum;
        }
    }

    public int sumRange(int i, int j) {
        if (i == 0)
            return csum[j];
        return csum[j] - csum[i-1];
    }
}
