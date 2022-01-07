#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int brackets[1001][1001];
    int dp[1001][1001];
    
    void getParanthesis(int i, int j, char &name, string &ans){
        if(i == j){
            ans += name;
            name++;
            return;
        }
        ans += '(';
        getParanthesis(i, brackets[i][j], name, ans);
        getParanthesis(brackets[i][j] + 1, j, name, ans);
        ans += ')';
    }
    int MCM(int ar[], int i, int j){
        int mn = INT_MAX;
        if(i>=j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        for(int k=i; k <= j-1; k++){
            int tmpans = MCM(ar, i, k) + MCM(ar, k+1, j) + ar[i-1]*ar[k]*ar[j];
            if(tmpans < mn){
                mn = tmpans;
                brackets[i][j] = k;
            }
        }
        return dp[i][j] = mn;
    }
    string matrixChainOrder(int p[], int n){
        // code here
        memset(dp, -1, sizeof(dp));
        memset(brackets, 0 , sizeof(brackets));
        int cost = MCM(p, 1, n-1);
        char name = 'A';
        string ans = "";
        getParanthesis(1, n-1, name, ans);
        return ans;
    }
};