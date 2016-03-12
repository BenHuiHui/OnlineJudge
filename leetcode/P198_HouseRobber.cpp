//
//  P198_HouseRobber.cpp
//  LeetCode-Template
//
//  Created by Hui Hui on 12/3/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.size()<=0) {
            return 0;
        }
        
        vector<int>maxVal;
        maxVal.push_back(nums[0]);
        
        for (int i=1; i<nums.size(); i++) {
            
            if (i == 1) {
                maxVal.push_back(max(nums[0], nums[1]));
            }
            
            else{
                int val1 = maxVal[i-1];
                int val2 = maxVal[i-2] + nums[i];
                maxVal.push_back(max(val1, val2));
            }
        }
        
        return maxVal[nums.size()-1];
    }
};

int main(int argc, char *argv[]){
    
}