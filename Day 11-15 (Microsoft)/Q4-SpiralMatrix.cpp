#include <bits/stdc++.h>
using namespace std;

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ans;
        int ele = 1;
        int rs = 0, re = r-1, cs = 0, ce = c-1;
        while(ele <= r*c){
            for(int i=cs; i<=ce; i++)
                ans.push_back(matrix[rs][i]), ele++;
            rs++; if(ele > r*c) break;
            for(int i=rs; i<=re; i++)
                ans.push_back(matrix[i][ce]), ele++;
            ce--; if(ele > r*c) break;
            for(int i=ce; i>=cs; i--)
                ans.push_back(matrix[re][i]), ele++;
            re--; if(ele > r*c) break;
            for(int i=re; i>=rs; i--)
                ans.push_back(matrix[i][cs]), ele++;
            cs++; if(ele > r*c) break;
        }
        return ans;
    }
};