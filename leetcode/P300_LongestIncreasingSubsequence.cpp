//
//  P300_LongestIncreasingSubsequence.cpp
//  CppPlayground
//
//  Created by Hui Hui on 14/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if (nums.size()<=0) return 0;
        
        vector<int>longest(nums.size(), 1);
        int max = 1;
        
        longest[0] = 1;
        
        for (int i=1; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                
                if (nums[i] > nums[j]) {
                    int len = longest[j]+1;
                    if (len > longest[i]) {
                        longest[i] = len;
                    }
                }
                
                
                
            }
            
            if (max < longest[i]) {
                max = longest[i];
            }
        }
        
        
        return max;
    }
};