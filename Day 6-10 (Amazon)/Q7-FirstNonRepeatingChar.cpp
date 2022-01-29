#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
            queue<char> q;
            vector<int> vis(26, 0);
            string ans = "";
            for(char c: A){
                q.push(c);
                vis[c-'a']++;
                while(!q.empty() && vis[q.front()-'a']>1) 
                    q.pop();
                if(!q.empty())
                    ans += q.front();
                else 
                    ans += '#';
            }
            return ans;
		}
};

// https://www.youtube.com/watch?v=4kqz5e9kIuQ