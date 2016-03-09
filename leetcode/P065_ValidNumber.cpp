//
//  P065_ValidNumber.cpp
//  CppPlayground
//
//  Created by Hui Hui on 11/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        
        //Remove trailing and leading space
        s = trim(s);
        
        if (s.length() <= 0) {
            return false;
        }
        
        //Find special character e
        int pos = -1;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == 'e') {
                pos = i;
                break;
            }
        }
        
        if (pos == -1) {
            return isDouble(s);
        }
        
        else{
            string first = s.substr(0, pos);
            string second = s.substr(pos+1);
            
            //Empty before character 'e'
            if (first.length() <= 0) {
                return false;
            }
            
            //Empty after character 'e'
            if (second.length() <= 0) {
                return false;
            }
            
            //string after e must be an integer
            if (second[0] == '+' || second[0] == '-') {
                second = second.substr(1);
            }
            
            //Empty after character 'e'
            if (second.length() <= 0) {
                return false;
            }
            
            return isDouble(first) && isInteger(second);
        }
    }
    
private:
    
    //Can be empty
    bool isDouble(string s){
        
        if (s.length() <= 0) {
            return true;
        }
        
        int start = 0;
        
        if (s[0] == '+' || s[0] == '-') {
            start = 1;
        }
        
        //Empty
        if (start >= s.length()) {
            return false;
        }
        
        //Find special character '.'
        int pos = -1;
        
        for (int i=start; i<s.length(); i++) {
            if (s[i] == '.') {
                pos = i;
                break;
            }
        }
        
        if (pos == -1) {
            return isInteger(s.substr(start));
        }
        else{
            string first = s.substr(start, pos-start);
            string second = s.substr(pos+1);
            
            if (first.length() <= 0 && second.length() <= 0) {
                return false;
            }
            
            return isInteger(first) && isInteger(second);
        }
    }
    
    bool isInteger(string s){
        
        for (int i=0; i<s.length(); i++) {
            if (s[i] > '9' || s[i] <'0') {
                return false;
            }
        }
        
        return true;
    }
    
    string trim(string& s)
    {
        
        size_t p = s.find_first_not_of(" ");
        s.erase(0, p);
        
        p = s.find_last_not_of(" ");
        if (string::npos != p)
            s.erase(p+1);
        
        return s;
    }
};

/*
 
 Testcases:
 1. e9 => false
 2. " " => false
 3. "+3.4e-.2" => false
 */

int main(int argc, char* argv[]){
    Solution s;
    string input = "3 ";
    cout << s.isNumber(input);
}
