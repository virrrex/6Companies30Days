#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool iscycle(vector<int> adj[],vector<int> &vis,int id){
        if(vis[id] == 1)
            return true;
        if(vis[id] == 0){
            vis[id] = 1;
            for(auto edge : adj[id]){
                if(iscycle(adj,vis,edge))
                    return true;
            }
        }
        vis[id] = 2;
        return false;
    }
    
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
        for(auto edge : prerequisites)
            adj[edge.second].push_back(edge.first);
        vector<int> vis(N, 0);
        
        for(int i=0; i<N; i++){
            if(iscycle(adj, vis, i))
                return false;
        }
        return true;
	}
};

// Similar to course schedule leetcode