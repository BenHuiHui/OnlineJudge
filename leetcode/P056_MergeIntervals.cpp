//
//  P056_MergeIntervals.cpp
//  CppPlayground
//
//  Created by Hui Hui on 14/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include "leetcode_util/Interval.h"

#include <vector>
using namespace std;

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        vector<Interval> solution;
        
        if (intervals.size() <= 0) {
            return solution;
        }
        
        sort(intervals.begin(), intervals.end(), [](const Interval&left, const Interval&right){
            
            //Error 1 : return bool
            return left.start < right.start;
        });
        
        Interval inter = intervals[0];
        
        int index = 1;
        
        while (index < intervals.size()) {
            
            Interval next = intervals[index];
            
            //merge
            if (next.start <= inter.end) {
                
                //Error 2 : use max rather than next.end
                inter.end = max(next.end, inter.end);
            }
            
            else{
                solution.push_back(inter);
                inter = next;
            }
            index++;
        }
        
        solution.push_back(inter);
        
        
        return solution;
    }
};