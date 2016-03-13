//
//  P221_MaximalSquare.cpp
//  LeetCode-Template
//
//  Created by Hui Hui on 13/3/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        vector<vector<int>>numberOfOne;
        for (long i=0; i<matrix.size(); i++) {
            numberOfOne.push_back(vector<int>(matrix[i].size(), 0));
        }
        
        for (int i=0; i<matrix.size(); i++) {
            
            int one = 0;
            
            for (long j=matrix[i].size()-1; j>=0; j--) {
                
                if (matrix[i][j] == '1') {
                    one ++;
                }
                else
                    one = 0;
                
                numberOfOne[i][j] = one;
                
            }
            
        }
        
        int max = 0;
        
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                
                int length = numberOfOne[i][j];
                
                //Calculate max rectange starting from this point
                for (int k=i; k<matrix.size(); k++) {
                    
                    if (matrix[k][j] == '0') {
                        break;
                    }
                    
                    length = min(length, numberOfOne[k][j]);
                    
                    if ((k-i+1) > length) {
                        break;
                    }
                    
                    int area = (k-i+1) * (k - i + 1);
                    if (max < area)
                        max = area;
                }
                
                
            }
        }
        
        return max;
    }
};

int main(int argc, char *argv[]){
    Solution sln;
    vector<vector<char>>mat;
    vector<char>row;
    row.push_back('0');
    row.push_back('1');
    mat.push_back(row);
    
    cout << sln.maximalSquare(mat);
}
