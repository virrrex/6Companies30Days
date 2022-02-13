#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        // Your code here
        int c1 = INT_MAX, c2 = INT_MAX, c3 = INT_MAX, a = 0;
        for (int x : arr) {
            if (x <= c1)
                c1 = x;           
            else if (x <= c2){
                c2 = x;
                a = c1;
            }
            else {
                c3 = x;
                break;
            }
        }
        vector<int> ans;
        if(c3 != INT_MAX)
            ans.push_back(a), ans.push_back(c2), ans.push_back(c3);
        return ans;
    }
};

//  LC 334