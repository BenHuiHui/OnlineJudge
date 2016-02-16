//
//  P268_MissingNumber.cpp
//  CppPlayground
//
//  Created by Hui Hui on 16/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int i=0;
        int size = (int)nums.size();
        
        while (i<size) {
            
            if (nums[i] == i || nums[i] >= size) {
                i++;
            }
            
            else{
                int index= nums[i];
                int temp = nums[i];
                nums[i] = nums[nums[i]];
                nums[index] = temp;
            }
        }
        
        for (int i=0; i<size; i++) {
            if (nums[i]!=i) {
                return i;
            }
        }
        return size;
    }
};

int main(int argc, char* argv[]){
    Solution sln;
    vector<int> arr = {1, 0};
    cout << sln.missingNumber(arr);
}