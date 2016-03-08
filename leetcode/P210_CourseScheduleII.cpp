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
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int>sln;
        
        vector<vector<int>>dependency;
        for (int i=0; i<numCourses; i++) {
            vector<int>a;
            dependency.push_back(a);
        }
        
        //Read in dependency
        for (pair<int, int> d : prerequisites){
            dependency[d.second].push_back(d.first);
        }
        
        //Check if it has cycle
        if (hasCycle(dependency)) {
            return sln;
        }
        
        //Topological sort
        vector<bool>visited(numCourses, false);
        
        for (int i=0; i<numCourses; i++) {
            topologicalSort(dependency, sln, visited, i);
        }
        
        //Reverse
        vector<int>reversed;
        for (int i=numCourses-1; i>=0; i--) {
            reversed.push_back(sln[i]);
        }
        
        return reversed;
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
    
    void topologicalSort(vector<vector<int>>&dependency, vector<int>&sln, vector<bool>& visited, int curr){
        
        if (visited[curr]) {
            return;
        }
        
        visited[curr] = true;
        
        vector<int>adj = dependency[curr];
        
        for (int a : adj){
            
            if (visited[a]) {
                continue;
            }
            
            topologicalSort(dependency, sln, visited, a);
        }
        
        sln.push_back(curr);
    }
};


int main(int argc, char *argv[]){
    int numCourses = 2;
    vector<pair<int, int>>pre;
    pre.push_back(pair<int, int>(0, 1));
    pre.push_back(pair<int, int>(1, 0));
    
    Solution sln;
    
    vector<int> s = sln.findOrder(numCourses, pre);
    cout << "Solution: ";
    
    for (int i=0; i<s.size(); i++) {
        cout << s[i] << " ";
    }
}
