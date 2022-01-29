#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool subsetSum(int arr[], int n, int sum) {
        int dp[n+1][sum+1];
        for(int i=0; i<=n; i++)
            for(int j=0; j<=sum; j++){
                if(i==0)
                    dp[i][j] = false;
                if(j==0)
                    dp[i][j] = true;
            }
        
        for(int i=1; i<=n; i++)
            for(int j=1; j<=sum; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        return dp[n][sum];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = accumulate(arr, arr+N, 0);
        if(sum & 1)
            return 0;
        return subsetSum(arr, N, sum/2);
    }
};