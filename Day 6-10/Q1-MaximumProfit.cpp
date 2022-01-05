#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<vector<int>>> mem;
    
    int recursion(int prices[], int n, int k, int pos, bool bought){
        if(k == 0 || pos >= n)
            return 0;
        if(mem[bought][k][pos] != -1)
            return mem[bought][k][pos];
        
        int sum = recursion(prices, n, k, pos+1, bought);   // SKIP
        if(bought)
            sum = max(sum, recursion(prices, n, k-1, pos+1, false) + prices[pos]);  // SELL
        else 
            sum = max(sum, recursion(prices, n, k, pos+1, true) - prices[pos]);     // BUY 
        
        return mem[bought][k][pos] = sum;
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        mem.resize(2, vector<vector<int>> (K+1, vector<int> (N, -1)));
        return recursion(A, N, K, 0, false);
    }
};