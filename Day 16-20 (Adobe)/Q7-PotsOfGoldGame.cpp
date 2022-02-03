#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>&A,int n, int start, int end, vector<vector<int>>& dp) {
        
        if(end < start) 
            return 0;
        
        if(end == start) 
            return A[end];
        
        if(dp[start][end] != -1) return dp[start][end];
        
        return dp[start][end] = max({
            A[start] + min(maxCoins(A, n, start + 2, end, dp), maxCoins(A, n, start + 1, end - 1, dp)),
            A[end]   + min(maxCoins(A, n, start, end - 2, dp), maxCoins(A, n, start + 1, end - 1, dp))
        });
    }
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    vector<vector<int>> dp(n, vector<int>(n, -1));
	    return maxCoins(A, n, 0, n-1, dp);
    }
};