#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string ans = "";
        for(char c: s) {
            if(isupper(c)) {
                if(ans.size()) 
                    ans += ' ';
                ans += tolower(c);
                // ans += (c - 'A' + 'a');
            }
            else
                ans += c;
        }
        return ans;
    }
};