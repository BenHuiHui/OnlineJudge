package leetcode;

/*
Important
This version TLE O(n^3)
JiuZhang: solution => the last character must belongs to some substring ends at that index
 */
public class P132_PalindromePartitioningII {

    public int minCut(String s) {

        int[][] min = new int[s.length()][s.length()];

        for (int i = 0; i < min.length; i++) {
            for (int j = 0; j < min[0].length; j++) {
                min[i][j] = -1;
            }
        }

        boolean[][] isPalimdrone = getIsPalindrome(s);

        return minCut(s, 0, s.length()-1, min, isPalimdrone);
    }

    public int minCut(String s, int start, int end, int[][]min, boolean[][] isPalimdrome){

        if (min[start][end] != -1) return min[start][end];

        if (isPalimdrome[start][end])
            return min[start][end] = 0;

        int min_cut = Integer.MAX_VALUE;

        for (int i = start; i < end; i++) {

            int left = minCut(s, start, i, min, isPalimdrome);
            int right = minCut(s, i+1, end, min, isPalimdrome);

            int total = left + right + 1;

            if (min_cut > total)
                min_cut = total;

        }

        return min[start][end] = min_cut;
    }

    private boolean[][] getIsPalindrome(String s) {
        boolean[][] isPalindrome = new boolean[s.length()][s.length()];

        for (int i = 0; i < s.length(); i++) {
            isPalindrome[i][i] = true;
        }
        for (int i = 0; i < s.length() - 1; i++) {
            isPalindrome[i][i + 1] = (s.charAt(i) == s.charAt(i + 1));
        }

        for (int length = 2; length < s.length(); length++) {
            for (int start = 0; start + length < s.length(); start++) {
                isPalindrome[start][start + length]
                        = isPalindrome[start + 1][start + length - 1] && s.charAt(start) == s.charAt(start + length);
            }
        }

        return isPalindrome;
    }


}
