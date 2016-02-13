//
//  P090_SubsetsII.cpp
//  CppPlayground
//
//  Created by Hui Hui on 12/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> results;
        
        vector<int>curr;
        
        sort(nums.begin(), nums.end());
        
        results.push_back(curr);
        
        subsetsWithDup(nums, curr, 0, results);
        
        return results;
        
    }
    
    void subsetsWithDup(const vector<int> &nums, vector<int> & curr, int index, vector<vector<int>> &results){
        
        for (int i=index; i<nums.size(); i++) {
            
            vector<int> newCurr(curr.begin(), curr.end());
            
            newCurr.push_back(nums[i]);
            results.push_back(newCurr);
            
            subsetsWithDup(nums, newCurr, i+1, results);
            
            //Pass duplicates
            while (nums[i] == nums[i+1]) {
                i++;
            }
            
        }
    }
    
};
