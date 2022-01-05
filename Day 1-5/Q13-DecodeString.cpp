#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int i = 0;
    // repeats a string for given number of times
    string repeat(string s, int times) {
        for(int n = s.size(); --times; s += s.substr(0,n));
        return s;
    }
    string decodedString(string s){
        // code here
        string ans = "", num = "";
        while(i < s.size() && s[i] != ']') {
            for(; i < s.size() && isalpha(s[i]); i++)
                ans += s[i];
            if(i >= s.size() || s[i] == ']') continue;
            for(num = ""; i < s.size() && isdigit(s[i]); i++)
                num += s[i];
            i++;
            ans += repeat(decodedString(s), stoi(num));
            i++;
        }
        return ans;
    }
};