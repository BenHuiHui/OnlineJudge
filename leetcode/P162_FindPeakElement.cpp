//
//  P162_FindPeakElement.cpp
//  CppPlayground
//
//  Created by Hui Hui on 14/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int lo=0, hi=(int)nums.size()-1;
        int mid=0;
        while (lo<=hi) {
            
            if (lo == hi) {
                return lo;
            }
            
            mid = lo + (hi-lo)/2;
            
            if ((mid==0 || nums[mid]>nums[mid-1]) && (mid==nums.size()-1 || nums[mid]>nums[mid+1])) {
                return mid;
            }
            
            if (mid==0 || nums[mid]>nums[mid-1]) {
                lo = mid+1;
            }
            
            else {
                hi = mid-1;
            }
        }
        
        return lo;
    }
};