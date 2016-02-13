//
//  P216_CombinationSumIII.cpp
//  CppPlayground
//
//  Created by Hui Hui on 13/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int>curr;
        
        combinationSum3(k, n, 1, result, curr);
        
        return result;
    }
    
    void combinationSum3(int k, int n, int start, vector<vector<int>>&results, vector<int>curr){
        
        if (n == 0 && k==0) {
            results.push_back(curr);
        }
        
        if (start > n || k<=0 || start>9) {
            return;
        }
        
        combinationSum3(k, n, start+1, results, curr);
        
        curr.push_back(start);
        combinationSum3(k-1, n-start, start+1, results, curr);
        
    }
};