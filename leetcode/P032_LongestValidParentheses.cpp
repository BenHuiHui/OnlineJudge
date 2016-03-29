//
//  P032_LongestValidParentheses.cpp
//  CppPlayground
//
//  Created by Hui Hui on 15/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int max = 0;
        
        int curr = 0;
        
        stack<int>st;
        
        for (int i=0; i<s.length(); i++) {
            char c = s[i];
            
            if (c == '('){
                st.push(c);
            }
            
            else{
                
                if (st.size() <= 0) {
                    curr = 0;
                }
                
                else{
                    st.pop();
                    curr++;
                    if (curr > max) {
                        max = curr;
                    }
                }
                
            }
        }
        
        return max*2;
    }
};
