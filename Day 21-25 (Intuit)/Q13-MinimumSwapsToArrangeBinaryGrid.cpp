#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> suffix0(n);
        for(int i=0; i<n; i++) {
            int count = 0;
            while(count < n && grid[i][n - count - 1] == 0) ++count;
            suffix0[i] = count;
        }
        int count = 0;

        for(int i=0; i<n; i++) {
            int j = i;
            while(j<n && suffix0[j] < n-1-i) j++;

            if(j == n) return -1;
            for(; j>i; j--) {
                swap(suffix0[j], suffix0[j-1]);
                count++;
            }
        }
        return count;
    }
};