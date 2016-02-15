//
//  P37_SudokuSolver.cpp
//  CppPlayground
//
//  Created by Hui Hui on 15/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        int rows[9];
        int cols[9];
        int mats[9];
        
        for (int i=0; i<9; i++) {
            rows[i] = 0;
            cols[i] = 0;
            mats[i] = 0;
        }
        
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    
                    rows[i] |= 1<<num;
                    cols[j] |= 1<<num;
                    
                    int m = toMat(i, j);
                    mats[m] |= 1<<num;
                }
                
            }
        }
        
        solveSudoku(board, 0, 0, rows, cols, mats);
        
    }
    
    bool solveSudoku(vector<vector<char>>& board, int i, int j, int *rows, int *cols, int *mats){
        
        //Last entry
        if (i==8 && j==8) {
            
            if (board[i][j] != '.') {
                return true;
            }
            
            else{
                
                vector<int> avail = availableNumber(i, j, rows, cols, mats);
                
                if (avail.size() > 0) {
                    board[i][j] = '0'+avail[0];
                    return true;
                }
                else
                    return false;
            }
        }
        
        int nextJ = (j+1)%9;
        int nextI = i + (j/8);
        
        if (board[i][j] != '.') {
            return solveSudoku(board, nextI, nextJ, rows, cols, mats);
        }
        else{
            
            vector<int>avail = availableNumber(i, j, rows, cols, mats);
            
            if (avail.size() <= 0) {
                return false;
            }
            
            for (int i=0; i<avail.size(); i++) {
                
                int num = avail[i];
                board[i][j] = '0'+num;
                
                int m = toMat(i, j);
                rows[i] |= 1<<num;
                cols[j] |= 1<<num;
                mats[m] |= 1<<num;
                
                bool success = solveSudoku(board, nextI, nextJ, rows, cols, mats);
                
                if (success) {
                    return success;
                }
                
                board[i][j] = '.';
                rows[i] &= ~(1<<num);
                cols[j] &= ~(1<<num);
                mats[m] &= ~(1<<num);
            }
            
            return false;
        }
    }
    
    vector<int> availableNumber(int i, int j, int*row, int *cols, int *mats){
        
        vector<int>avail;
        
        for (int num=1; num<=9; num++) {
            
            if ((row[i]&(1<<num)) == 0) {
                if ((cols[j]&(1<<num)) == 0) {
                    
                    int m = toMat(i, j);
                    if ((mats[m]&(1<<num))==0) {
                        avail.push_back(num);
                    }
                    
                }
            }
            
        }
        
        
        return avail;
        
    }
    
    int toMat(int i, int j){
        return 3 * (i / 3) + j / 3;
    }
    
};

int main(int argc, char *argv[]){
    vector<vector<char>>soduku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    Solution s;
    s.solveSudoku(soduku);
    
    for (int i=0; i<soduku.size(); i++) {
        for (int j=0; j<soduku[0].size(); j++) {
            cout<<soduku[i][j] << " ";
        }
        cout<<endl;
    }
    
}

