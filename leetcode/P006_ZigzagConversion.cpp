//
//  P006_ZigzagConversion.cpp
//  LeetCode-Template
//
//  Created by Hui Hui on 8/3/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1)return s;
        long len = s.size(), k = 0, interval = (nRows<<1)-2;
        
        string res(len, ' ');
        for(int j = 0; j < len ; j += interval)//处理第一行
            res[k++] = s[j];
        for(int i = 1; i < nRows-1; i++)//处理中间行
        {
            long inter = (i<<1);
            for(int j = i; j < len; j += inter)
            {
                res[k++] = s[j];
                inter = interval - inter;
            }
        }
        for(int j = nRows-1; j < len ; j += interval)//处理最后一行
            res[k++] = s[j];
        return res;
    }
};