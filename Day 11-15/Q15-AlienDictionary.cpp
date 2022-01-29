#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string topologicalSort(char parent, unordered_map<char, vector<char>> &G, unordered_set<char> &visited) {
        if(visited.count(parent)) return "";
        visited.insert(parent);
        if(G.count(parent) == 0) return string(1, parent);

        string ans = "";
        for(auto child: G[parent]) {
            ans += topologicalSort(child, G, visited);
        }

        ans += parent;
        return ans;
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        unordered_map<char, vector<char>> G;
        for(int i = 1; i < N; i++) {
            int j = 0;
            int limit = min(dict[i-1].size(), dict[i].size());

            while(j < limit && dict[i-1][j] == dict[i][j]) j++;

            if(j < limit) G[dict[i-1][j]].push_back(dict[i][j]);
        }

        unordered_set<char> visited;
        string ans_rev = "";

        for(auto node: G) {
            if(visited.count(node.first)) continue;
            ans_rev += topologicalSort(node.first, G, visited);
        }

        reverse(ans_rev.begin(), ans_rev.end());

        return ans_rev;
    }
};