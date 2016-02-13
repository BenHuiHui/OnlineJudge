package leetcode;

import java.util.Scanner;

/**
 * Created by huihui on 3/2/16.
 */

//Problem: out of index line 15 for empty matrix

public class P329_LongestIncreasingPathInMatrix {

    public int longestIncreasingPath(int[][] matrix) {

        int[][] len = new int[matrix.length][matrix[0].length];

        int max = 0;

        if (matrix.length <= 0) return 0;

        for (int i = 0; i < len.length; i++) {
            for (int j = 0; j < len[0].length; j++) {

                int length = longestIncreasingPath(matrix, len, i, j);

                if (max < length)
                    max = length;
            }
        }


        return max;
    }

    public int longestIncreasingPath(int[][] matrix, int[][] len, int i, int j){

        if (len[i][j] > 0) return len[i][j];

        int length = 1;

        int neighbor = 0;

        if (i > 0 && matrix[i][j] > matrix[i-1][j]){
            int left = longestIncreasingPath(matrix, len, i-1, j);
            if (left > neighbor)
                neighbor = left;
        }

        if (j > 0 && matrix[i][j] > matrix[i][j-1]){
            int left = longestIncreasingPath(matrix, len, i, j-1);
            if (left > neighbor)
                neighbor = left;
        }

        if (i < matrix.length-1 && matrix[i][j] > matrix[i+1][j]){
            int left = longestIncreasingPath(matrix, len, i+1, j);
            if (left > neighbor)
                neighbor = left;
        }

        if (j < matrix[0].length-1 && matrix[i][j] > matrix[i][j+1]){
            int left = longestIncreasingPath(matrix, len, i, j+1);
            if (left > neighbor)
                neighbor = left;
        }

        return len[i][j] = length + neighbor;
    }

    public static void main(String[] args){

        /*
        3 3 9 9 4 6 6 8 2 2 1

        3 3 3 4 5 3 2 6 2 2 1
         */


        Scanner in = new Scanner(System.in);

        int m = in.nextInt();
        int n = in.nextInt();

        int[][] mat = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = in.nextInt();
            }
        }

        P329_LongestIncreasingPathInMatrix p = new P329_LongestIncreasingPathInMatrix();

        System.out.println(p.longestIncreasingPath(mat));

    }

}
