#include <bits/stdc++.h>
using namespace std;

string encode(string src) {     
    //Your code here 
    int count = 1;
    string ans = "";
    char ch = src[0];
    for(int i=1; i < src.length(); i++) {
        if(src[i] == src[i-1])
            count++;
        else {
            ans += ch;
            ans += ('0' + count);
            count = 1;
            ch = src[i];
        }
    }
    ans += ch;
    ans += ('0' + count);
    return ans;
} 