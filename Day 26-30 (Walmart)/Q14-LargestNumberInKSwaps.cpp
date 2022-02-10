#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(string str, int n, int k, string &ans, int index){
        if(k == 0) return;
        char maxchar = str[index];
        for(int i=index+1; i<n; i++)
            if(maxchar < str[i])
                maxchar = str[i];
        if(maxchar != str[index])
            k--;
        for(int i=n-1; i>=index; i--){
            if(str[i] == maxchar){
                swap(str[index], str[i]);
                if(ans < str)
                    ans = str;
                solve(str, n, k, ans, index+1);
                swap(str[index], str[i]);
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans = str;
       int n = str.size();
       solve(str, n, k, ans, 0);
       return ans;
    }
};

//  YT - https://www.youtube.com/watch?v=ZnfqHvAt9bE