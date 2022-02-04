#include <bits/stdc++.h>
using namespace std;

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> ans;
        int mx = -1;
        for(int i=n-1; i>=0; i--){
            if(a[i] >= mx){
                ans.push_back(a[i]);
                mx = a[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};