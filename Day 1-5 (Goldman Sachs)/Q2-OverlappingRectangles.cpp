#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // code here
        // x-axis overlap & y-axis overlap check
        return (L1[0] <= R2[0] && L2[0] <= R1[0]) && (R1[1] <= L2[1] && R2[1] <= L1[1]);
    }
};