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
#include <unordered_set>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool success = solve(board);
        cout << (success ? "True" : "False") << endl;
    }
    
    bool solve(vector<vector<char>>& board){
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                
                if (board[i][j] != '.') {
                    continue;
                }
                
                for (int k=1; k<10; k++) {
                    
                    board[i][j] = (char)'0'+k;
                    
                    if (isValid(board, i, j) && solve(board)) {
                        return true;
                    }
                    
                    board[i][j] = '.';
                }
                
                return false;
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
    
    /*
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
     */
};

int main(int argc, char *argv[]){
    
    /*
     ...36.4.7
     .......6.
     ....5.3.8
     .5..4..8.
     ......92.
     79.582..3
     .4.....39
     8........
     .36...5..
     
     
...36.4.7.......6.....5.3.8.5..4..8.......92.79.582..3.4.....398.........36...5..
     
     
63..74.91.9........2...5....81..7..6....5.......8.63..5...4..6.7..6.81....8....79
     
     
     */
    
    vector<vector<char>>soduku;
    string input;
    cin>>input;
    
    for (int i=0; i<9; i++) {
        vector<char>row(9);
        for (int j=0; j<9; j++) {
            row[j] = input[i*9+j];
        }
        soduku.push_back(row);
    }
    
    Solution s;
    s.solveSudoku(soduku);
    
    for (int i=0; i<soduku.size(); i++) {
        for (int j=0; j<soduku[0].size(); j++) {
            cout<<soduku[i][j] << " ";
        }
        cout<<endl;
    }
    
}

