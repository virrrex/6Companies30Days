#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int sum[2] = {};
        for (int i = 0, N = colors.size(); i < N;) {
            int c = colors[i], cnt = 0;
            while (i < N && c == colors[i]) ++i, ++cnt;
            sum[c - 'A'] += max(0, cnt - 2);
        }
        return sum[0] > sum[1];
    }
};