//
//  P219_ContainsDuplicateII.cpp
//  CppPlayground
//
//  Created by Hui Hui on 15/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_set<int>occurrences;
        
        
        for (int i=0; i<=k && i<nums.size(); i++) {
            
            if (occurrences.find(nums[i]) != occurrences.end()) {
                return true;
            }
            
            occurrences.insert(nums[i]);
        }
        
        for (int i=k+1; i<nums.size(); i++) {
            
            occurrences.erase(nums[i-k-1]);
            
            if (occurrences.find(nums[i]) != occurrences.end()) {
                return true;
            }
            
            occurrences.insert(nums[i]);
        }
        
        
        return false;
    }
};