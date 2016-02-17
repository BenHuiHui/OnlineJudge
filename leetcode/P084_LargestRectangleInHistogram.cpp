//
//  P084_LargestRectangleInHistogram.cpp
//  LeetCode-Template
//
//  Created by Hui Hui on 17/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
  
        int max = 0;
        int total = (int)heights.size();
        stack<pair<int, int>>st;
        
        for (int i=0; i<heights.size(); i++) {
            
            int start = i;
            int height = heights[i];

            //Remove smaller
            while (!st.empty() && height <= st.top().first ) {
                
                    pair<int, int>rect = st.top();
                    
                    int area = rect.first * (i - rect.second);
                    
                    if (max < area) {
                        max = area;
                    }
                    
                    start = rect.second;
                    
                    st.pop();
                
            }
            
            st.push(pair<int, int>(heights[i], start));
        }
        
        while (!st.empty()) {
            
            pair<int, int>rect = st.top();
            
            int area = rect.first * (total - rect.second);
            
            if (area > max) {
                max = area;
            }
            
            st.pop();
        }
        
        return max;
    }
};


int main(int argc, char*argv[]){
    Solution sln;
    vector<int>arr = {2,1,5,6,2,3};
    cout << sln.largestRectangleArea(arr);
}