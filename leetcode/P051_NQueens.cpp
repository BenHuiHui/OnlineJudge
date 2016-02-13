//
//  P051_NQueens.cpp
//  CppPlayground
//
//  Created by Hui Hui on 11/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>solution;
        vector<int>used(n);
        
        totalNQueens(n, 0, used, solution);
        return solution;
    }
    
    void totalNQueens(int n, int row, vector<int>&used, vector<vector<string>>&solution){
        
        for (int i=0; i<n; i++) {
            if (isValid(i, row, used)) {
                
                if (row == n-1) {
                    used[row] = i;
                    printState(used, solution);
                }
                else{
                    used[row] = i;
                    totalNQueens(n, row+1, used, solution);
                }
            }
        }
        
    }
    
    bool isValid(int pos, int row, vector<int>& used){
        
        for (int i=0; i<row; i++) {
            
            if (used[i] == pos) {
                return false;
            }
            
            int pos_diff = used[i]>pos ? used[i]-pos : pos -used[i];
            int row_diff = row - i;
            
            if (pos_diff == row_diff) {
                return false;
            }
        }
        
        return true;
    }
    
    void printState(vector<int>&used, vector<vector<string>>&solutions){

        vector<string> state;

        for (int i=0; i<used.size(); i++) {
            
            string s(used.size(), '.');
            s[used[i]] = 'Q';
            
            state.push_back(s);
        }
        
        solutions.push_back(state);
    }
};