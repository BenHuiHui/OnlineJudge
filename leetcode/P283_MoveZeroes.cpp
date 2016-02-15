//
//  P283_MoveZeroes.cpp
//  CppPlayground
//
//  Created by Hui Hui on 15/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int lo=0;
        
        for (int hi=0; hi<nums.size(); hi++) {
            
            if (nums[hi] != 0) {
                nums[lo++] = nums[hi];
            }
            
        }
        
        for (int i=lo; i<nums.size(); i++) {
            nums[i]=0;
        }
    }
};