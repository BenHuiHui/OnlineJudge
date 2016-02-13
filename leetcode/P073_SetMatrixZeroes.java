package leetcode;

import java.util.Scanner;

/**
 * Created by huihui on 4/2/16.
 */
public class P073_SetMatrixZeroes {

    public void setZeroes(int[][] matrix) {

        int row = -1, col = -1;

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {

                if (matrix[i][j] == 0){

                    if (row == -1){
                        row = i;
                        col = j;
                    }
                    else {
                        matrix[row][j] = 0;
                        matrix[i][col] = 0;
                    }

                }

            }
        }

        if (row != -1){

            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix[0].length; j++) {

                    if (i != row && j!=col)
                        if (matrix[i][col] == 0 || matrix[row][j] == 0)
                            matrix[i][j] = 0;
                }
            }

            for (int i = 0; i < matrix.length; i++) {
                matrix[i][col] = 0;
            }

            for (int i = 0; i < matrix[0].length; i++) {
                matrix[row][i] = 0;
            }

        }

    }

    public static void main(String[] args){

        /*
        5 4 0 0 0 5 4 3 1 4 0 1 1 4 1 2 1 3 0 0 1 1
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

        P073_SetMatrixZeroes p = new P073_SetMatrixZeroes();
        p.setZeroes(mat);

    }


}
