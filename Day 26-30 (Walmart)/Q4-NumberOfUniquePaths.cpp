#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        int N = a + b - 2;  // total steps to reach 
        int r = a - 1;
        // calculate nCr
        double res = 1;
        for(int i=1; i<=r; i++)
            res = res * (N-r+i) / i;
        return (int)res;
    }
};

//  LC 62