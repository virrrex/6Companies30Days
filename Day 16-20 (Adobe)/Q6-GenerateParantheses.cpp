#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void solve(int o, int c, string op, vector<string> &ans){
        if(o == 0 && c == 0){
            ans.push_back(op);
            return;
        }
        string op1 = op + '(';
        string op2 = op + ')';
        
        if(o != 0)
            solve(o-1, c, op1, ans);
        if(c>o)
            solve(o, c-1, op2, ans);
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        int open = n, close = n;
        string op = "";
        vector<string> ans;
        solve(open, close, op, ans);
        return ans;
    }
};

//  LC 22