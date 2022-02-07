#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int height(int N){
        // code here
        return (-1 + sqrt(1 + 8*N))/2;
    }
};