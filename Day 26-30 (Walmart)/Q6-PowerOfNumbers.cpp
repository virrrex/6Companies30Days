#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //You need to complete this fucntion
    long long MOD = 1e9+7;
    long long power(int N,int R)
    {
       //Your code here
        long long ans = 1.0;
        long long x = N;
        while(R){
            if(R&1){
                ans = (ans * x) % MOD;
                R--;
            }
            else{
                x = (x * x) % MOD;
                R >>= 1;
            }
        }
        return ans;
    }

};