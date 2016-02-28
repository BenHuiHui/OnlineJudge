import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

/**
 * Created by huihui on 28/2/16.
 */
public class P031_NextPermutation {

    public void nextPermutation(int[] nums) {

        int right = nums.length-1;

        while (right >= 1 && nums[right] <= nums[right-1])
            right --;

        if (right == 1)
            Arrays.sort(nums);

        else{
            int index = right-1;
            int max = Integer.MAX_VALUE;

            //Find min in the right that is greater than target number
            for (int i = right; i < nums.length; i++) {
                if (nums[i] > nums[right-1] && nums[i] < max){
                    index = i;
                    max = nums[i];
                }
            }

            //Swap
            int tmp = nums[index];
            nums[index] = nums[right-1];
            nums[right-1] = tmp;
            Arrays.sort(nums, right, nums.length);
        }

    }


}
