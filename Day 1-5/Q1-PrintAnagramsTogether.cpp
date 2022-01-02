#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        unordered_map<string, vector<string>> mp;
        for(auto &str: string_list) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            mp[sortedStr].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it: mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};