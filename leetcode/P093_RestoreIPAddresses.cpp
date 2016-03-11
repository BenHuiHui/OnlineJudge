//
//  P093_RestoreIPAddresses.cpp
//  LeetCode-Template
//
//  Created by Hui Hui on 11/3/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
        vector<string>results;
        
        if (s.length() < 4) {
            return results;
        }
        
        vector<vector<vector<string>>>ips;
        
        for (int i=0; i<s.length(); i++) {
            
            vector<vector<string>> currVector;
            
            for (int j=i; j>=max(0, i-2); j--) {
                
                string curr = s.substr(j, (i-j+1));
                
                if (isValid(curr)) {
                    
                    if (j>0) {
                        
                        vector<vector<string>>prev = ips[j-1];
                        for (vector<string>p : prev){
                            if (p.size()<4) {
                                p.push_back(curr);
                                currVector.push_back(p);
                            }
                        }
                        
                    }
                    
                    else{
                        currVector.push_back(vector<string>(1, curr));
                    }
                }
            }
            ips.push_back(currVector);
        }
        
        //Generate
        vector<vector<string>>last = ips[ips.size()-1];
        
        for (vector<string>ip : last){
            
            if (ip.size()!=4) {
                continue;
            }
            
            string s;
            for (int i=0; i<3; i++) {
                s += ip[i]+".";
            }
            s+= ip[3];
            results.push_back(s);
        }
        
        return results;
    }
    
    bool isValid(string s){
        if (s.length() >= 4) {
            return false;
        }
        
        if (s[0] == '0' && s.size()>1) {
            return false;
        }
        
        return stoi(s) <= 255;
    }
    
};

int main(int argc, char * argv[]){
    Solution s;
    vector<string>ips = s.restoreIpAddresses("010010");
    for (string ip : ips)
        cout << ip << endl;
}