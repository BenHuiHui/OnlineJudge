/**
 * Created by huihui on 19/3/16.
 */
public class P260_SingleNumberIII {

    public int[] singleNumber(int[] nums) {

        int result = nums[0];
        for (int i=1; i<nums.length;i++)
            result ^= nums[i];

    //Get the rightmost digit that is not 0
        int lastBit = result & (~(result-1));

        int result1 = 0;
        int result2 = 0;

        int[] results = new int[2];

        for(int i=0; i<nums.length;i++){
            if((nums[i] & lastBit ) > 0){
                result1 ^= nums[i];
            }
            else
                result2 ^= nums[i];
        }

        results[0] = result1;
        results[1] = result2;

        return results;
    }

}
