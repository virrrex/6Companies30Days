#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n =  points.size();
        vector<unordered_map<int, int>> dist(n);
    
        for(int i=0; i<n; i++) {
            for(int j =i+1; j<n; j++) {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                int distance = x*x + y*y;
                dist[i][distance]++;
                dist[j][distance]++;
            }
        }
        int ans = 0;
        for(auto point: dist) {
            for(auto d: point) {
                ans += d.second * (d.second - 1);
            }
        }
        return ans;
    }
};