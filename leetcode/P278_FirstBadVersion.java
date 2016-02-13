package leetcode;

/**
 * Created by huihui on 7/2/16.
 */
public class P278_FirstBadVersion {

    public int firstBadVersion(int n) {
        int lo = 0;
        int hi = n-1;
        int mid = n/2;

        while (lo <= hi){
            if (isBadVersion(mid)){
                hi = mid - 1;
            }

            else{
                lo = mid + 1;
            }

            mid = lo + (hi - lo )/2;
        }

        return lo;
    }

    boolean isBadVersion(int version){
        return true;
    }
}
