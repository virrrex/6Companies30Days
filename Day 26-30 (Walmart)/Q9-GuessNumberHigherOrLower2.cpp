#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAmount(int start, int end, vector<vector<int>> &dp) {
        if(end == start)
            return 0;
        if(end - start == 1)
            return min(start, end);
        if(dp[start][end] != -1) return dp[start][end];
        int ans = INT_MAX;
        for(int i=start+1; i<end; i++) {
            ans = min(ans, i + max(maxAmount(start, i-1, dp), maxAmount(i+1, end, dp)));
        }
        return dp[start][end] = ans;
    }
    
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return maxAmount(1, n, dp);
    }
};