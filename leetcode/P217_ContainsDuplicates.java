package leetcode;

import java.util.HashSet;

/**
 * Created by huihui on 29/1/16.
 */
public class P217_ContainsDuplicates {

    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> cache = new HashSet<Integer>();

        for (int i=0; i<nums.length; i++)
            if (cache.contains(nums[i]))
                return true;
            else
                cache.add(nums[i]);

        return false;
    }

}
