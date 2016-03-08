//
//  P210_CourseScheduleII.cpp
//  LeetCode-Template
//
//  Created by Hui Hui on 18/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<vector<int>>dependency;
        for (int i=0; i<numCourses; i++) {
            vector<int>a;
            dependency.push_back(a);
        }
        
        //Read in dependency
        for (pair<int, int> d : prerequisites){
            dependency[d.second].push_back(d.first);
        }
        
        return !hasCycle(dependency);
    }
    
    bool hasCycle(vector<vector<int>>&dependency){
        vector<int>visited(dependency.size(), 0);
        
        for (int i=0; i<dependency.size(); i++) {
            if (hasCycle(dependency, visited, i)) {
                return true;
            }
        }
        
        return false;
    }
    
    bool hasCycle(vector<vector<int>>&dependency, vector<int>&visited, int start){
        
        //Explored before
        if (visited[start] == 2) {
            return false;
        }
        
        vector<int>adj = dependency[start];
        bool hasCyc = false;
        
        visited[start] = 1;
        
        for (int neighbor : adj){
            
            if (visited[neighbor] == 1) {
                return true;
            }
            
            if (visited[neighbor] == 0) {
                hasCyc = hasCyc || hasCycle(dependency, visited, neighbor);
            }
        }
        
        visited[start] = 2;
        
        return hasCyc;
    }
};