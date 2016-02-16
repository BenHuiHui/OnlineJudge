//
//  P201_BitwiseANDOfNumbersRange.cpp
//  CppPlayground
//
//  Created by Hui Hui on 16/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        vector<int>indexes;
        
        int start = m;
        int index = 0;
        
        while (start > 0) {
            
            if ((start & 1) > 0) {
                indexes.push_back(index);
            }
            
            start = start >> 1;
            index++;
            
        }
        
        for (int i=m+1; i<=n; i++) {
            
            vector<int>newIndexes;
            
            for (int j=0; j<indexes.size(); j++) {
                int index = indexes[j];
                if ((i&1<<index) > 0) {
                    newIndexes.push_back(index);
                }
            }
            
            indexes = newIndexes;
            
            if (indexes.size()<=0) {
                break;
            }
        }
        
        int result = 0;
        
        for (int i=0; i<indexes.size(); i++) {
            result |= 1<<indexes[i];
        }
        
        return result;
    }
};

int main(int argc, char*argv[]){
    Solution sln;
    cout << sln.rangeBitwiseAnd(2, 3);
}