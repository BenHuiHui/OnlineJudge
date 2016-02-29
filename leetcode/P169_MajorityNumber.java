/**
 * Created by huihui on 29/2/16.
 */
public class P169_MajorityNumber {

    public int majorityElement(int[] nums) {

        if (nums.length <= 0) return 0;
        int count = 1;
        int target = nums[0];

        for (int i=1; i<nums.length; i++){
            if (count == 0){
                count = 1;
                target = nums[i];
            }

            else {
                if (target == nums[i]){
                    count ++;
                }
                else
                    count --;
            }
        }
        return target;
    }

}
