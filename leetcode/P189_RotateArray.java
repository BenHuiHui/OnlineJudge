/**
 * Created by huihui on 27/2/16.
 */
public class P189_RotateArray {

    public void rotate(int[] nums, int k) {

        int n = nums.length;
        k = k%n;

        if (k == 0) return;

        reverse(nums, 0, n-k-1);
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-1);
    }

    public void reverse(int[] nums, int start, int end){

        while (start <= end) {

            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;

            start++;
            end--;
        }
    }
}
