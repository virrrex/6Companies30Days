#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        if(n == 1) return n;
        int result = 0;
        vector<unordered_map<int, int>> dp(n);
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                int diff = A[i] - A[j];
                dp[i][diff] = dp[j].count(diff) > 0 ? dp[j][diff] + 1 : 2;
                result = max(result, dp[i][diff]);
            }
        }
        return result;
    }
};

// LC 1027