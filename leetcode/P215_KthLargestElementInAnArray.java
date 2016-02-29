/**
 * Created by huihui on 29/2/16.
 */
public class P215_KthLargestElementInAnArray {

    public int findKthLargest(int[] nums, int k) {

        k = nums.length-k+1;

        int left =0, right = nums.length-1;

        while (left <= right){

            int target = nums[left];

            int i=left+1, j=right;

            while (i<=j) {

                while (i <= j && nums[i] < target) i++;
                while (i <= j && nums[j] >= target) j--;

                if (i < j) {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    i++;
                    j--;
                }
            }

            nums[left] = nums[j];
            nums[j] = target;

            int size = j-left+1;
            if (size == k) return nums[j];
            else if (size < k) {
                left = j+1;
                k = k-size;
            }
            else{
                right = j-1;
            }
        }

        return -1;
    }

    public static void main(String[] args){
        int[] nums = {2,1};
        int k = 1;

        P215_KthLargestElementInAnArray p = new P215_KthLargestElementInAnArray();
        System.out.print(p.findKthLargest(nums, k));
    }

}
