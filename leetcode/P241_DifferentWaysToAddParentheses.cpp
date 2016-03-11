//
//  P241_DifferentWaysToAddParentheses.cpp
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
    vector<int> diffWaysToCompute(string input) {
        
        vector<string>expression;
        
        if (input.size() <= 0) {
            return vector<int>();
        }
        
        //Parse input
        string num = "";
        
        for (int i=0; i<input.length(); i++) {
            
            char c = input[i];
            
            if (c == '+' || c=='-' || c=='*') {
                
                expression.push_back(num);
                num = "";
                
                expression.push_back(input.substr(i, 1));
            }
            
            else{
                num += c;
            }
        }
        expression.push_back(num);
        
        return evaluate(expression, 0, expression.size()-1);
        
    }
    
    vector<int> evaluate(vector<string>& expression, long start, long end){
        
        vector<int>results;
        
        if (start == end) {
            results.push_back(stoi(expression[start]));
            return results;
        }
        
        for (long i=start+1; i<end; i+=2) {
            
            vector<int>left = evaluate(expression, start, i-1);
            vector<int>right = evaluate(expression, i+1, end);
            
            for (int l : left){
                for (int r : right){
                    
                    int result = 0;
                    
                    if (expression[i].compare("+") == 0) {
                        result = l + r;
                    }
                    
                    else if (expression[i].compare("-") == 0)
                        result = l - r;
                    else
                        result = l * r;
                    
                    results.push_back(result);
                }
            }
        }
        
        return results;
    }
    
};

int main(int argc, char * argv[]){
    Solution s;
    vector<int> res = s.diffWaysToCompute("0");
}
