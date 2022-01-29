#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(int n) {
        // 1^2 + 2^2 + 3^2 + ...
        return (n * (n+1) / 2) * (2*n + 1) / 3;
    }
};