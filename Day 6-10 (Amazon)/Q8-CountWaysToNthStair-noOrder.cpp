#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {
        // your code here
        return m/2 + 1ll;
    }
};

// https://stackoverflow.com/questions/62871148/count-ways-to-nth-stairorder-does-not-matter