package leetcode;

/**
 * Created by huihui on 1/2/16.
 */
public class P097_InterleavingStrings {

    public boolean isInterleave(String s1, String s2, String s3) {

        /*
        if (s1.length() + s2.length() != s3.length())
            return false;

        return isInterleave(s1, s2, s3, 0, 0, 0);
        */

        //Bottom - up

        if (s1.length() + s2.length() != s3.length())
            return false;

        boolean[][] matched = new boolean[s1.length()+1][s2.length()+1];

        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                matched[i][j] = false;
            }
        }

        matched[0][0] = true;


        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {

                if (i > 0)
                    matched[i][j] = matched[i][j] || ( matched[i-1][j] && s1.charAt(i-1) == s3.charAt(i+j-1) );

                if (j > 0)
                    matched[i][j] = matched[i][j] || ( matched[i][j-1] && s2.charAt(j-1) == s3.charAt(i+j-1) );
            }
        }


        return matched[s1.length()][s2.length()];
    }

    private boolean isInterleave(String s1, String s2, String s3, int i, int j ,int k){

        if (k == s3.length()) return true;

        boolean match = false;

        if (i < s1.length() && s1.charAt(i) == s3.charAt(k))
            match = match || isInterleave(s1, s2 , s3, i+1, j, k+1);

        if (j < s2.length() && s2.charAt(j) == s3.charAt(k))
            match = match || isInterleave(s1, s2, s3, i, j+1, k+1);

        return match;
    }

    public static void main(String[] args){
        P097_InterleavingStrings p = new P097_InterleavingStrings();

        String s1 = "aabcc";
        String s2 = "dbbca";
        String s3 = "aadbbcbcac";
        String s4 = "aadbbbaccc";

        System.out.println(p.isInterleave(s1, s2, s3));
        System.out.println(p.isInterleave(s1, s2, s4));

    }


}
