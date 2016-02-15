//
//  P003_LongestSubstringWithoutRepeatingCharacters.cpp
//  CppPlayground
//
//  Created by Hui Hui on 15/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int max = 0;
        
        int lo=0, hi=0;
        
        unordered_set<int>occurrence;
        
        for (; hi<s.length(); hi++) {
            
            if (occurrence.find(s[hi]) != occurrence.end()) {
                
                while (s[lo] != s[hi]) {
                    occurrence.erase(s[lo]);
                    lo++;
                }
                lo++;
                
                int len = hi-lo+1;
                if (max < len) {
                    max = len;
                }
            }
            
            else{
                int len = hi-lo+1;
                if (max < len) {
                    max = len;
                }
                occurrence.insert(s[hi]);
            }
            
        }
        
        return max;
        
    }
};