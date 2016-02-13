package leetcode;

/**
 * Created by huihui on 8/2/16.
 */
public class P079_WordSearch {

    public boolean exist(char[][] board, String word) {

        boolean[][] used = new boolean[board.length][board[0].length];

        for (int i = 0; i < used.length; i++) {
            for (int j = 0; j < used[0].length; j++) {
                used[i][j] = false;
            }
        }

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (exist(board, word, 0, i, j, used))
                    return true;
            }
        }

        return false;
    }

    public boolean exist(char[][] board, String word, int index, int i, int j, boolean[][]used){

        if (i<0 || i>=board.length || j<0 || j>=board[0].length)
            return false;

        if (used[i][j])
            return false;

        if (board[i][j] != word.charAt(index))
            return false;

        if (index == word.length()-1)
            return true;

        int[] rows = {1, -1, 0, 0};
        int[] cols = {0, 0, 1, -1};

        boolean exists = false;

        used[i][j] = true;

        for (int k = 0; k < 4; k++) {
            exists = exists || exist(board, word, index+1, i+rows[k], j+cols[k], used);
        }

        used[i][j] = false;

        return exists;
    }

    public static void main(String[] args){
        char[][] words = {
                {'A', 'B'},
                {'C', 'D'}
        };
        String patt = "ABD";
        P079_WordSearch p = new P079_WordSearch();
        System.out.println(p.exist(words, patt));
    }

}
