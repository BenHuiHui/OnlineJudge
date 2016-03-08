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
            return findKthSmallest(nums1, nums2, 0, size1-1, 0, size2-1, (size1 + size2)/2);
        }
        else{
            
            return 0.5 * (findKthSmallest(nums1, nums2, 0, size1-1, 0, size2-1, (size1 + size2)/2-1)
                          + findKthSmallest(nums1, nums2, 0, size1-1, 0, size2-1, (size1 + size2)/2));
        }
    }
    
    double findKthSmallest(vector<int>&nums1, vector<int>&nums2, long start1, long end1, long start2, long end2, long k){
        
        long size1 = end1 - start1 + 1;
        long size2 = end2 - start2 + 1;
        
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
        
        if (mid1 < mid2) {
            
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
    
};

int main(int argc, char *argv[]){
    Solution s;
    vector<int>nums1 = {1, 1};
    vector<int>nums2 = {1, 1};
    std::cout << s.findMedianSortedArrays(nums1, nums2);
}
