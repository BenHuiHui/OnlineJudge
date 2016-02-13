package leetcode;

/**
 * Created by huihui on 1/2/16.
 */
public class P115_DistinctSubsequences {

    public int numDistinct(String s, String t) {

        int[][] occurr = new int[t.length()][s.length()];

        for (int i = 0; i < s.length(); i++) {
           occurr[0][i] = s.charAt(i) == t.charAt(0) ? 1 : 0;
        }

        for (int i = 1; i < t.length(); i++) {
            for (int j = 0; j < s.length(); j++) {

                if (s.charAt(j) == t.charAt(i)){

                    int sum = 0;

                    for (int k = 0; k < j; k++) {
                        sum += occurr[i-1][k];
                    }

                    occurr[i][j] = sum;

                }
                else
                    occurr[i][j] = 0;

            }
        }

        int sum = 0;

        for (int i = 0; i < s.length(); i++) {
            sum += occurr[t.length()-1][i];
        }

        return sum;
    }


    public static void main(String[] args){
        P115_DistinctSubsequences p = new P115_DistinctSubsequences();
        String s = "rabbbit";
        String t = "rabbit";
        System.out.println(p.numDistinct(s, t));
    }


}
