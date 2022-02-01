#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int kvowelwords(int N, int K) {
        // Write Your Code here
        long long mod = 1e9+7;

        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        dp[1][0] = 21;
        long long sum = 21;

        if(K > 0) {
            dp[1][1] = 5;
            sum += 5;
        }

        for(int n = 2; n <= N; n++) {
            sum = dp[n][0] = (sum * 21ll) % mod;
            for(int k = 1; k <= K; k++) {
                sum += dp[n][k] = (dp[n - 1][k - 1]*5ll) % mod;
                sum %= mod;
            }
        }

        return sum;
    }
};

//  YT: https://www.youtube.com/watch?v=KyHYIxtwh9A