#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int calc_area(int r, int c, vector<vector<int>>& grid) {

        int R = grid.size();
        int C = grid[0].size();

        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 0;

        int area = 0;

        while(!q.empty()) {
            ++area;

            pair<int, int> block = q.front();
            r = block.first;
            c = block.second;

            int dx[8] = {0,0,1,-1,-1,-1,1,1};
            int dy[8] = {1,-1,0,0,1,-1,1,-1};
            
            for(int i=0; i<8; i++){
                int nx = r + dx[i], ny = c + dy[i];
                if(nx < 0 || ny < 0 || nx >= R || ny >= C || grid[nx][ny] != 1)
                    continue;
                q.push({nx, ny});
                grid[nx][ny] = 0;
            }

            q.pop();
        }

        return area;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int max_area = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int r = 0; r < n; ++r) {
            for(int c = 0; c < m; ++c) {
                if(grid[r][c]) {
                    max_area = max(max_area, calc_area(r, c, grid));
                }
            }
        }
        
        return max_area;
    }
};