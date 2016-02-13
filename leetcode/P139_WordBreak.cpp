//
//  P139_WordBreak.cpp
//  CppPlayground
//
//  Created by Hui Hui on 10/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        
        bool exists[s.length()+1];
        
        for (int i=0; i<=s.length(); i++) {
            exists[i] = false;
        }
        
        exists[0] = true;
        
        for (int i=1; i<=s.length(); i++) {
            for (int j=1; j<=i; j++) {
                
                if (exists[i]) {
                    break;
                }
                else{
                    exists[i] = exists[i] || (exists[i-j] && wordDict.find(s.substr(i-j, j)) != wordDict.end());
                }
                
            }
        }
        
        return exists[s.length()];
    }
};
