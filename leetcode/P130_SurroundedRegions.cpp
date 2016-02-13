//
//  P130_SurroundedRegions.cpp
//  CppPlayground
//
//  Created by Hui Hui on 13/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
// ["XXX","XOX","XXX"]


/*
 DFS Runtime error reason stack overflow
 */

#include <stdio.h>

#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        //Error
        if (board.size() <= 0) {
            return;
        }
        
        for (int i=0; i<board.size(); i++) {
            flipRec(board, i, 0, 'O', '-');
            flipRec(board, i, (int) board[0].size()-1, 'O', '-');
        }
        
        for (int i=0; i<board[0].size(); i++) {
            flipRec(board, 0, i, 'O', '-');
            flipRec(board, (int)board.size() -1, i, 'O', '-');
        }
        
        flip(board, 'O', 'X');
        flip(board, '-', 'O');
    }
    
    void flipRec(vector<vector<char>>& board, int i, int j, char original, char newChar){
        
        if (i<0 || i>=board.size() || j<0 || j>= board[0].size()) {
            return;
        }
        
        if (board[i][j] != original) {
            return;
        }
        
        board[i][j] = newChar;
        
        int row[] = {1, -1, 0, 0};
        int col[] = {0, 0, 1, -1};
        
        for (int k=0; k<4; k++) {
            flipRec(board, i+row[k], j+col[k], original, newChar);
        }
    }
    
    void flip(vector<vector<char>>& board, char original, char newChar){
        
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == original) {
                    board[i][j] = newChar;
                }
                
            }
        }
        
    }
};

/*
int main(int argc, char* argv[]){
    Solution s;
    vector<vector<int>> board;
}
*/