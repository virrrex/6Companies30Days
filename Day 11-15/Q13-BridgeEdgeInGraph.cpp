#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int root , vector<int> & vis , vector<int> adj[] , int c , int d){
	    vis[root] = 1 ;
	    for(auto e : adj[root]){
	        if((root == c && e == d) || (root == d and e == c))
	            continue ;
	        
	        if(!vis[e])
	            dfs(e,vis,adj,c,d) ;
	    }
	}
	
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int> vis(V,0) ;
        
        dfs(c,vis,adj,c,d) ;
        if(!vis[d]) 
            return 1 ;
        else  
            return  0 ;
    }
};