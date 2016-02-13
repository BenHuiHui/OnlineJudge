//
//  P179_LargestNumber.cpp
//  CppPlayground
//
//  Created by Hui Hui on 11/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string>numsStr(nums.size());
        
        for (int i=0; i<nums.size(); i++) {
            numsStr[i] = to_string(nums[i]);
        }
        
        sort(numsStr.begin(), numsStr.end(), [](const string &left, const string &right){
            
            string s1 = left + right;
            string s2 = right + left;
            return s1 < s2;
            
        });
        
        string s;
        
        for (int i= (int)nums.size()-1; i>=0; i--) {
            s += numsStr[i];
        }
        
        if (s[0] == '0') {
            s = "0";
        }
        
        return s;
    }
};


int main (int argc, char *argv[]){
    
    Solution s;
    
    vector<int>arr = {3, 25, 4};
    string res = s.largestNumber(arr);
    cout << res;
    
    return 0;
}
