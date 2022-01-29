#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0, up = 0, down = 0;
        for(int i=1; i<arr.size(); i++) {
            if((down && arr[i-1] < arr[i]) || arr[i-1] == arr[i])
                up = down = 0;
            up += arr[i-1] < arr[i];
            down += arr[i-1] > arr[i];
            if(up && down)
                ans = max(ans, up + down + 1);
        }
        return ans;
    }
};