#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans = "";

        while(n) {
            ans = (char) ('A' + (n-1) % 26) + ans;
            n = (n-1)/26;
        }
        
        return ans;
    }
};