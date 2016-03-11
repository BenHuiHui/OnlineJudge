//
//  P131_PalindromePartitioning.cpp
//  LeetCode-Template
//
//  Created by Hui Hui on 11/3/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        if (s.length() <= 0) {
            return vector<vector<string>>();
        }
        
        vector<vector<vector<string>>> list;
        
        //Put first element
        vector<vector<string>> first;
        first.push_back(vector<string>(1, s.substr(0, 1)));
        list.push_back(first);
        
        for (int i=1; i<s.length(); i++) {
            
            vector<vector<string>> curr;
            
            for (int j=0; j<=i; j++) {
                
                string substring = s.substr(j, i-j+1);
                
                if (isPalindrome(substring)) {
                    
                    if (j > 0 ) {
                        
                        vector<vector<string>> prev = list[j-1];
                        for (int k=0; k<prev.size(); k++) {
                            vector<string>bbb = prev[k];
                            bbb.push_back(substring);
                            curr.push_back(bbb);
                        }
                        
                    }
                    
                    else{
                        curr.push_back(vector<string>(1, s.substr(j, i-j+1)));
                    }
                    
                }
                
            }
            list.push_back(curr);
        }
        
        
        return list[list.size()-1];
    }
    
    bool isPalindrome(string s){
        long i=0, j=s.length()-1;
        
        while (i<=j) {
            if (s[i]!=s[j]) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    
};