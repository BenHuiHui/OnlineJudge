package leetcode;

/**
 * Created by huihui on 29/1/16.
 */

/*
User n/mid < mid rather than mid*mid to avoid overflow
 */

public class P069_Sqrt {
    public int mySqrt(int x) {

        if(x<=1) return x;
        int start=0, end=x;
        while(start<=end) {
            int mid = start + (end-start)/2;
            if(x/mid==mid)
                return mid;
            else if(x/mid<mid)
                end = mid-1;
            else
                start = mid+1;
        }
        return end;

        }

}

