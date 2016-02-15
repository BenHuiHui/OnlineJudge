//
//  P36_ValidSudoku.cpp
//  CppPlayground
//
//  Created by Hui Hui on 15/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                
                if (board[i][j] == '.') {
                    continue;
                }
                
                if (!isValid(board, i, j)) {
                    return false;
                }
                
            }
        }
        return true;
    }
    
    
    bool isValid(vector<vector<char>>&board, int i, int j){
        
        unordered_set<char>rows;
        unordered_set<char>cols;
        unordered_set<char>mats;
        
        //Rows
        for (int k=0; k<9; k++) {
            if (rows.find(board[i][k]) != rows.end()) {
                return false;
            }
            if (board[i][k] != '.') {
                rows.insert(board[i][k]);
            }
        }
        
        for (int k=0; k<9; k++) {
            if (cols.find(board[k][j]) != cols.end()) {
                return false;
            }
            if (board[k][j] != '.') {
                cols.insert(board[k][j]);
            }
        }
        
        vector<vector<int>>indexes = {{0,1,2},{3,4,5},{6,7,8}};
        
        for (int row : indexes[i/3]){
            for (int col : indexes[j/3]){
                
                if (mats.find(board[row][col]) != mats.end()) {
                    return false;
                }
                
                if (board[row][col] != '.') {
                    mats.insert(board[row][col]);
                }
            }
        }
        
        return true;
    }
};
