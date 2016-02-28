/**
 * Created by huihui on 28/2/16.
 */
public class P172_FactorialTrailingZeroes {

    public int trailingZeroes(int n) {
        if (n < 5) return 0;
        return n / 5 + trailingZeroes(n/5);
    }

}
