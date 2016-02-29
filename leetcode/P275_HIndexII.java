import java.util.Arrays;

/**
 * Created by huihui on 29/2/16.
 */
public class P275_HIndexII {
    public int hIndex(int[] citations) {
        //Arrays.sort(citations);

        int left = 0, right=citations.length-1;

        while (left <= right){

            int mid = left + (right - left)/2;
            int h = (citations.length - mid);
            if (citations[mid] >= h && (mid==0 || citations[mid-1] <= h)) return h;
            if (citations[mid] < h) left = mid+1;
            else right = mid-1;
        }

        return citations.length - left;
    }
}
