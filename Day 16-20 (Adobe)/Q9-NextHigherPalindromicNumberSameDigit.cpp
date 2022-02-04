#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
      void nextPermutation(string &str) {
        int n = str.size(), k, l;
        for(k = n-2; k>=0; k--)
            if(str[k] < str[k+1])
                break;
    
        if(k >= 0){
            for(l=n-1; l>k; l--)
                if(str[l] > str[k])
                    break;
            swap(str[k], str[l]);
            reverse(str.begin()+k+1, str.end());
        }
    }
    string nextPalin(string N) { 
        //complete the function here
        int sz = N.size();
        string s1 = N.substr(0, sz/2);
        string s2 = "";
        if(sz&1) s2 += N[sz/2];
        string test = s1;
        nextPermutation(test);
        if(s1 == test)
            return "-1";
        string rev = test; reverse(rev.begin(), rev.end());
        s2 = test + s2 + rev;
        return s2;
    }
};