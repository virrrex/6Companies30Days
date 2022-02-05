#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define pipii pair<int, pii>
#define N 1000

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        //code here
        int lo = INT_MAX, hi = INT_MIN;
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        for (int i=0; i<k; i++) {
            int val = KSortedArray[i][0];
            lo = min(lo, KSortedArray[i][0]);
            hi = max(hi, KSortedArray[i][0]);
            pq.push({val,{i, 0}});
        }
        
        vector<int> ans = {lo, hi};
        while (true) {
            pipii min_entry = pq.top(); pq.pop();

            int new_row = min_entry.second.first;
            int new_col = min_entry.second.second + 1;
            if(new_col >= n) break;

            int new_val = KSortedArray[new_row][new_col];
            pq.push({new_val, {new_row, new_col}});

            lo = pq.top().first;
            hi = max(hi, new_val);

            if(hi - lo < ans[1] - ans[0]) {
                ans[0] = lo;
                ans[1] = hi;
            }
        }
        return {ans[0], ans[1]};
    }
};

//  LC 632