#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long int mod = 1e9+7;
    long long int dp[1001][1002];
    long long int count(int n, int x, int k) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(k > n) return 0;

        if(dp[n][k] != -1) return dp[n][k];

        long long int ans = count(n - pow(k, x), x, k + 1) + count(n, x, k + 1);

        dp[n][k] = ans %= mod;

        return ans;
    }
    
    int numOfWays(int n, int x)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return count(n, x, 1);
    }
};