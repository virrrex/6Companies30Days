#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeInCircle(int n, int m, int k) {
        int ans = (n+k-1) % m;
        return ans == 0 ? m : ans;
    }
};