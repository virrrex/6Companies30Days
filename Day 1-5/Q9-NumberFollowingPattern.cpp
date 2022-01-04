#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int n = S.length();
        string ans(n+1, ' ');
        int count = 1;
        for(int i=0; i<n+1; i++) {
            if(i == n || S[i] == 'I'){
                for(int j = i; j>=0; j--){
                    ans[j] = '0' + count++;
                    if(S[j-1] == 'I')
                        break;
                }
            }
        }
        return ans;
    }
};