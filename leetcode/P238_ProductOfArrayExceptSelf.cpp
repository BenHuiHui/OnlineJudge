//
//  P238_ProductOfArrayExceptSelf.cpp
//  CppPlayground
//
//  Created by Hui Hui on 10/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> results(nums.size());
        
        int product = 1;
        
        results[0] = 1;
        for (int i = 0; i < nums.size()-1; i++) {
            product *= nums[i];
            results[i+1] = product;
        }
        
        
        product = nums[nums.size()-1];
        for (int i=(int)nums.size()-2; i>=0; i--) {
            results[i] *= product;
            product *= nums[i];
        }
        
        
        return results;
    }
};

/*
int main (int argc, char * argv[]){
    
    Solution s;
    vector<int>v = {1, 2, 3, 4};
    vector<int>w = s.productExceptSelf(v);
    
    for (int i=0; i<w.size(); i++) {
        cout<<w[i]<<" ";
    }
    
}
*/