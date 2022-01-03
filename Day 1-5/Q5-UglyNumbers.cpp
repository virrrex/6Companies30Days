#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

class Solution{
public:	
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    ull dp[n+1];
	    dp[0] = 1;
	    int c2(0), c3(0), c5(0);
	    for(int i = 1; i <= n; i++){
	        dp[i] = min({2*dp[c2], 3*dp[c3], 5*dp[c5]});
	        if(dp[i] == 2*dp[c2])
	            c2++;
	        if(dp[i] == 3*dp[c3])
	            c3++;
	        if(dp[i] == 5*dp[c5])
	            c5++;
	    }
	    return dp[n-1];
	}
};