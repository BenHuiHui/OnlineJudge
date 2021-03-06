//
//  P039_CombinationSum.cpp
//  CppPlayground
//
//  Created by Hui Hui on 16/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>sln;
        vector<int>curr;
        
        combinationSum2(candidates, target, 0, curr, sln);
        
        return sln;
    }
    
    void combinationSum2(vector<int>&candidates, int target, int index, vector<int>curr, vector<vector<int>>&sln){
        
        if (index >= candidates.size() || candidates[index] > target) {
            return;
        }
        
        if (target == candidates[index]) {
            curr.push_back(candidates[index]);
            sln.push_back(curr);
            return;
        }
        
        /*
         int newIndex = index;
         while (newIndex < candidates.size()-1 && candidates[newIndex] == candidates[newIndex+1]) {
         newIndex++;
         }
         newIndex++;
         */
        
        //Dont use current value
        combinationSum2(candidates, target, index+1, curr, sln);
        
        //Use the current value
        curr.push_back(candidates[index]);
        combinationSum2(candidates, target-candidates[index], index, curr, sln);
    }
};