//
//  P046_Permutations.cpp
//  CppPlayground
//
//  Created by Hui Hui on 13/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>results;
        sort(nums.begin(), nums.end());
        vector<int>curr;
        vector<bool>used(nums.size(), false);
        
        permuteUnique(results, nums, curr, used);
        
        return results;
    }
    
    void permuteUnique(vector<vector<int>>&solution, vector<int>&nums, vector<int>curr, vector<bool>&used){
        
        if (curr.size() == nums.size()) {
            solution.push_back(curr);
            return;
        }
        
        for (int i=0; i<nums.size(); i++) {
            
            if (!used[i]) {
                
                used[i] = true;
                curr.push_back(nums[i]);
                permuteUnique(solution, nums, curr, used);
                curr.pop_back();
                used[i] =false;
                
                while (nums[i] == nums[i+1]) {
                    i++;
                }
            }
            
        }
        
    }
    
};
