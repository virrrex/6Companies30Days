#include <bits/stdc++.h>
using namespace std;

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = accumulate(arr, arr+n, 0);
	    int half = sum/2;
	    bool dp[n+1][sum+1];
	    
	    for(int i=0; i<=sum; i++)
	        dp[0][i] = false;
	    for(int i=0; i<=n; i++)
	        dp[i][0] = true;
	    
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=sum; j++){
	            if(arr[i-1] <= j)
	                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
	            else 
	                dp[i][j] = dp[i-1][j];
	        }
	    }
	    int ans;
	    for(int i=half; i>=0; i--){
	        if(dp[n][i]){
	            ans = i;
	            break;
	        }
	    }
	    ans = sum - 2*ans;
	    return ans;
	} 
};