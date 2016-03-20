/**
 * Created by huihui on 20/3/16.
 */
public class P152_MaximumProductSubarray {

    public int maxProduct(int[] nums) {

        if(nums.length<=0) return 0;
        if(nums.length < 1) return nums[1];

        int max = Integer.MIN_VALUE;
        int start = 0;
        boolean hasZero = false;

        for(int i=0; i<nums.length; i++)
            if(nums[i] == 0){
                hasZero = true;
                int maxSub = maxProduct(nums, start, i-1);
                if (max < maxSub) max = maxSub;
                start = i+1;
            }

        int maxSub = maxProduct(nums, start, nums.length-1);
        if (max < maxSub) max = maxSub;

        if (hasZero && max < 0) max = 0;
        return max;
    }

    public int maxProduct(int[] nums, int start, int end){
        if(start > end) return Integer.MIN_VALUE;
        if(start == end) return nums[start];

        int numberOfNegative = 0;

        for(int i=start; i<=end; i++)
            if(nums[i]<0)
                numberOfNegative ++;

        //Even
        if(numberOfNegative % 2 == 0){
            int product = 1;
            for (int i=start; i<=end; i++)
                product *= nums[i];
            return product;
        }

        //Odd
        else{

            //Get first and last nonzero
            int first = -1;
            int last = -1;

            for(int i=start; i<=end; i++)
                if(nums[i] < 0){
                    if (first == -1) first = i;
                    last = i;
                }

            //Compare two versions
            int common = 1;
            for(int i=first+1; i<last; i++){
                common *= nums[i];
            }

            int product1 = 1;
            int product2 = 1;

            for(int i=start; i<=first && i< last; i++)
                product1 *= nums[i];
            product1 *= common;

            int start2 = last > first ? last : first+1;
            for(int i=start2; i<=end; i++)
                product2 *= nums[i];
            product2 *= common;

            return product1 > product2 ? product1 : product2;
        }
    }

}
