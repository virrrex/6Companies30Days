#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int helper(int idx, int nums[], int n, vector<int> &dp){
        if(idx >= n)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        return dp[idx] = max(nums[idx] + helper(idx+2, nums, n, dp), helper(idx+1, nums, n, dp));
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n + 1, -1);
        return helper(0, arr, n, dp);
    }
};