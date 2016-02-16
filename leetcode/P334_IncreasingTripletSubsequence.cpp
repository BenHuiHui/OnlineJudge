//
//  P334_IncreasingTripletSubsequence.cpp
//  CppPlayground
//
//  Created by Hui Hui on 16/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>len(nums.size(), 1);
        return increasingTriplet(nums, len, 1);
    }
    
    bool increasingTriplet(vector<int>& nums, vector<int>&len, int index){
        
        if (index >= nums.size()) {
            return false;
        }
        
        for (int i=index; i>=0; i--) {
            
            if (nums[index] > nums[i]) {
                
                int length = len[i]+1;
                
                if (length == 3) {
                    return true;
                }
                
                if (length > len[index]) {
                    len[index] = length;
                }
            }
        }
        
        return increasingTriplet(nums, len, index+1);
    }
};