package leetcode;

/**
 * Created by huihui on 4/2/16.
 */
public class P279_PerfectSquares {

    public int numSquares(int n) {

        int[] cache = new int[n+1];
        return numSquares(n, cache);
    }

    public int numSquares(int n, int[] cache){

        if (cache[n] != 0)
            return cache[n];

        int root = (int) Math.floor( Math.sqrt(n) );
        if (root * root == n)
            return cache[n] = 1;

        int min = Integer.MAX_VALUE;

        for (int i = 1; i <= root; i++) {
            int val = numSquares(n - i * i, cache);
            if (val < min)
                min = val;
        }

        return cache[n] = min + 1;
    }

    public static void main(String[] args){
        P279_PerfectSquares p = new P279_PerfectSquares();
        System.out.println(p.numSquares(12));
        System.out.println(p.numSquares(13));
    }
}
