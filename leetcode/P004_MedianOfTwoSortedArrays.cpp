//
//  P004_MedianOfTwoSortedArrays.cpp
//  CppPlayground
//
//  Created by Hui Hui on 13/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//


#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        long size1 = nums1.size();
        long size2 = nums2.size();
        
        if ((size1 + size2) % 2 == 1 ) {
            return findKthSmallest(nums1, nums2, 0, 0, (size1 + size2)/2+1);
        }
        else{
            
            return 0.5 * (findKthSmallest(nums1, nums2, 0, 0,(size1 + size2)/2)
                          + findKthSmallest(nums1, nums2, 0, 0, (size1 + size2)/2+1));
        }
    }
    
    double findKthSmallest(vector<int>&nums1, vector<int>&nums2, long start1, long start2, long k){
        
        if (start1 >= nums1.size()) {
            return nums2[start2+k-1];
        }
        
        if (start2 >= nums2.size()) {
            return nums1[start1+k-1];
        }
        
        if (k == 1) {
            return min(nums1[start1], nums2[start2]);
        }
        
        long mid1 = 0;
        long mid2 = 0;
        
        if (nums1.size() - start1 < nums2.size() - start2) {
            mid1 = k/2+start1-1 < nums1.size() ? k/2+start1-1 : nums1.size()-1;
            mid2 = start2 + (k-2- (mid1 - start1));
        }
        
        else{
            mid2 = k/2 + start2 - 1 < nums2.size() ? k/2+start2-1 : nums2.size()-1;
            mid1 = start1 + (k-2 - (mid2-start2));
        }
        
        if (nums1[mid1] == nums2[mid2]) {
            return nums1[mid1];
        }
        
        if (nums1[mid1] < nums2[mid2]) {
            return findKthSmallest(nums1, nums2, mid1+1, start2, k-(mid1+1-start1));
        }
        else{
            return findKthSmallest(nums1, nums2, start1, mid2+1, k-(mid2+1-start2));
        }
    }
    
    /*
    double findKthSmallest(vector<int>&nums1, vector<int>&nums2, long start1, long end1, long start2, long end2, long k){
        
        long size1 = end1 - start1 + 1;
        long size2 = end2 - start2 + 1;
        long midIndex1 = start1 + (size1-1)/2;
        long midIndex2 = start2 + (size2-1)/2;
        
        //Base condition
        if (size1 <= 0) {
            return nums2[start2+k];
        }
        
        if (size2 <= 0) {
            return nums1[start1+k];
        }
        
        int mid1 = nums1[start1 + (size1-1)/2];
        int mid2 = nums2[start2 + (size2-1)/2];
        
        if (mid1 == mid2 && (k == (size1/2 + size2/2) || k == (size1 + size2)/2)) {
            return mid1;
        }
        
        //Divide
        
        if (mid1 <= mid2) {
            
            if (k <= (size1+size2)/2) {
                return findKthSmallest(nums1, nums2, start1, end1, start2, start2+size2/2, k);
            }
            
            else
                return findKthSmallest(nums1, nums2, start1+size1/2, end1, start2, end2, k-size1/2);
        }
        else{
            
            if (k<=(size1+size2)/2) {
                return findKthSmallest(nums1, nums2, start1, start1+size1/2, start2, end2, k);
            }
            
            else
                return findKthSmallest(nums1, nums2, start1, end1, start2+size2/2, end2, k-size2/2);
        }
        
    }
     */
};

int main(int argc, char *argv[]){
    Solution s;
    vector<int>nums1 = {1};
    vector<int>nums2 = {1, 2};
    std::cout << s.findMedianSortedArrays(nums1, nums2);
}
