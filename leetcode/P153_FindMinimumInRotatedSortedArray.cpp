//
//  P153_FindMinimumInRotatedSortedArray.cpp
//  CppPlayground
//
//  Created by Hui Hui on 10/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int lo=0, hi=(int)nums.size()-1;
        return findMin(nums, lo, hi);
    }
    
    int findMin(vector<int>&nums, int start, int end){
        
        if (start == end) {
            return nums[start];
        }
        
        if (start == end-1) {
            return nums[start] < nums[end] ? nums[start] : nums[end];
        }
        
        int min = INT_MAX;
        
        int mid = start + (end - start) / 2;
        
        if (nums[mid] < nums[mid-1]) {
            return nums[mid];
        }
        
        if (nums[mid] > nums[start]) {
            //min = findMin(nums, mid+1, end);
            
            if(nums[mid] < nums[end]){
                min = findMin(nums, start, mid-1);
            }
            
            
            else if (nums[mid] > nums[end]){
                min = findMin(nums, mid+1, end);
            }
            
            else{
                min = findMin(nums, start, mid-1);
            }
            
        }
        
        else if (nums[mid] < nums[start]){
            min = findMin(nums, start, mid-1);
            
            /*
             if(nums[mid] < nums[end]){
             min = findMin(nums, start, mid-1);
             }
             
             else if (nums[mid] > nums[end]){
             
             }
             
             else{
             min = findMin(nums, start, mid-1);
             }
             */
        }
        
        //This case is complicated due to duplicates
        else{
            
            if(nums[mid] < nums[end]){
                min = findMin(nums, start, mid-1);
            }
            
            else if (nums[mid] > nums[end]){
                min = findMin(nums, mid+1, end);
            }
            
            //Both side
            else{
                
                min = findMin(nums, start, mid-1);
                int min2 = findMin(nums, mid+1, end);
                
                if (min > min2) {
                    min = min2;
                }
                
            }
        }
        
        return min;
        
    }
};
