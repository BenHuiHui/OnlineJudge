//
//  P052_NQueensII.cpp
//  CppPlayground
//
//  Created by Hui Hui on 13/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<int>used(n);
        //used[0]=2;
        //used[1]=0;
        return totalNQueens(n, 0, used);
    }
    
    int totalNQueens(int n, int row, vector<int>&used){
        
        int sum = 0;
        
        for (int i=0; i<n; i++) {
            if (isValid(i, row, used)) {
                
                if (row == n-1) {
                    sum += 1;
                }
                else{
                    used[row] = i;
                    sum += totalNQueens(n, row+1, used);
                }
            }
        }
        
        return sum;
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
    
};

int main(int argc, char *argv[]){
    Solution s;
    cout << s.totalNQueens(4);
}