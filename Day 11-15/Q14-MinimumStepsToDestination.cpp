#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minSteps(int D){
        // code here
        int step = 0, sum = 0;
        while(true){
            step++;
            sum += step;
            if(sum == D)
                return step;
            else if(sum > D && (sum-D)%2 == 0)
                return step;
        }
    }
};