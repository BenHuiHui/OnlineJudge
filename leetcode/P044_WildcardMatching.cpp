//
//  P044_WildcardMatching.cpp
//  LeetCode-Template
//
//  Created by Hui Hui on 9/3/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    //DP Memory limit exceeded. => Use another method
    
    /*
    bool isMatch(string s, string p) {
        
        int matched[s.length()][p.length()];
        for (int i=0; i<s.length(); i++) {
            for (int j=0; j<p.length(); j++) {
                matched[i][j] = -1;
            }
        }
        
        return isMatch(s, p, 0, 0, matched);
    }
    
    bool isMatch(string& s, string& p, int sIndex, int pIndex, int matched[][p.length()]){
        
        //Both has been used up
        if (pIndex >= p.length() && sIndex >= s.length()) {
            return true;
        }
        
        //Only p has been used up
        if (pIndex >= p.length()) {
            return false;
        }
        
        //Word has been used up, the remaining of p should only be '*'
        if (sIndex >= s.length()) {
            
            for (int i=pIndex; i<p.length(); i++) {
                if (p[i] != '*') {
                    return false;
                }
            }
            
            return true;
        }
        
        if (matched[sIndex][pIndex] != -1) {
            return matched[sIndex][pIndex] == 1;
        }
        
        bool match = true;
        
        if (p[pIndex] != '*' && p[pIndex] != '?') {
            match = (p[pIndex] == s[sIndex] && isMatch(s, p, sIndex+1, pIndex+1, matched));
        }
        
        else if(p[pIndex] == '?')
            match = isMatch(s, p, sIndex+1, pIndex+1, matched);
        else{
            match = isMatch(s, p, sIndex, pIndex+1, matched)
                    || isMatch(s, p, sIndex+1, pIndex+1, matched)
            || isMatch(s, p, sIndex+1, pIndex, matched);
        }
        
        matched[sIndex][pIndex] = match ? 1 : 0;
        return match;
        
    }
    */
};

int main(int argc, char * argv[]){
    Solution sln;
    string s = "aa";
    string p = "*";
    cout << sln.isMatch(s, p);
}
