#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool topoSort(int course, vector<vector<int>> &courses, vector<int> &state, vector<int> &ans) {
        if(state[course] == 2) return true;
        if(state[course] == 1) return false;

        state[course] = 1; // visited
        for(auto prerequisites: courses[course]) {
            if(!topoSort(prerequisites, courses, state, ans)) {
                return false;
            }
        }
        ans.push_back(course);
        state[course] = 2; // completed
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses);
        vector<int> state(numCourses, 0);
        for(auto course: prerequisites) 
            courses[course[0]].push_back(course[1]);
        
        vector<int> ans;
        for(int i = 0; i < numCourses; ++i) {
            if(state[i]) continue;
            if(!topoSort(i, courses, state, ans)) {
                return vector<int>(0);
            }
        }
        return ans;
    }
};