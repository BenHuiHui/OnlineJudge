/**
 * Created by huihui on 28/2/16.
 */
public class P240_Search2DMatrixII {

    public boolean searchMatrix(int[][] matrix, int target) {

        if (matrix.length <= 0) return false;

        int left = 0, right = matrix[0].length-1, row = 0;

        while (row < matrix.length && left <= right){

            if (target == matrix[row][right]) return true;
            else if (target < matrix[row][right]) right--;
            else row++;
        }

        return false;
    }

}
