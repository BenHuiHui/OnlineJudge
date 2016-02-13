package leetcode;


/**
 * Created by huihui on 3/2/16.
 */

//Key observation from this is to use log

public class P326_PowerOfThree {

    public boolean isPowerOfThree(int n) {
        if (n <= 0) return false;
        return n ==  Math.pow(3, Math.round( Math.log(n) / Math.log(3)));
    }

}
