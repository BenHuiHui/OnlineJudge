//
//  P058_LengthOfLastWord.cpp
//  CppPlayground
//
//  Created by Hui Hui on 15/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        long hi = s.length()-1;
        while (hi>=0 && s[hi] ==' ') {
            hi--;
        }
        
        long lo = hi;
        int len=0;
        
        while (lo>=0 && s[lo] != ' ') {
            lo--;
            len++;
        }
        
        return len;
    }
};