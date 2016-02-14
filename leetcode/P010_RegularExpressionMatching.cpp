//
//  P010_RegularExpressionMatching.cpp
//  CppPlayground
//
//  Created by Hui Hui on 11/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        
        if (p.length()<=0 && s.length()>0) {
            return false;
        }
        
        vector<vector<int>>match;
        
        for (int i=0; i<=s.length(); i++) {
            match.push_back(vector<int>(p.length(), -1));
        }
        
        return isMatch(s, p, 0, 0, match);
    }
    
    bool isMatch(string s, string p ,int index1, int index2, vector<vector<int>>&match){
        
        if (index1 == s.length() && index2 == p.length()) {
            return true;
        }
        
        
        if (index1 > s.length()) {
            return false;
        }
        
        
        if (index2 == p.length()) {
            return false;
        }
        
        if (match[index1][index2] != -1) {
            return match[index1][index2] == 1;
        }
        
        if (index1 == s.length()) {
            if (index2<p.length()-1 && p[index2+1] == '*') {
                bool su = isMatch(s, p, index1, index2+2, match);
                match[index1][index2] = su ? 1 : 0;
                return su;
            }
        }
        
        bool matched = false;
        
        bool currMatched = s[index1] == p[index2] || p[index2] == '.';
        
        //Zero or more
        if (index2<p.length()-1 && p[index2+1] == '*') {
            //Zero
            matched = matched || isMatch(s, p, index1, index2+2, match);
            
            //More
            if (currMatched) {
                
                //One
                matched = matched || isMatch(s, p, index1+1, index2+2, match);
                
                //MOre
                matched = matched || isMatch(s, p, index1+1, index2, match);
            }
        }
        else{
            if (currMatched) {
                matched = matched || isMatch(s, p, index1+1, index2+1, match);
            }
        }
        
        match[index1][index2] = matched ? 1 : 0;
        return matched;
        
    }
};

int main(int argc, char*argv[]){
    string s = "a";
    string p = ".*..a*";
    Solution sln;
    cout <<sln.isMatch(s, p);
}