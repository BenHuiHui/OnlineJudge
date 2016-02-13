package leetcode;

/**
 * Created by huihui on 2/2/16.
 */
public class P213_PowerOfTwo {

    public boolean isPowerOfTwo(int n) {
        if (n<=0) return false;
        return ((n-1)&n) == 0;
    }

}
