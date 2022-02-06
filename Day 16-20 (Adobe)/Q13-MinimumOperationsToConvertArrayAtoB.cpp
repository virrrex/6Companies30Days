#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        vector<int> LIS;
        unordered_set<int> set;
        for(int i=0 ; i<M; i++) 
            set.insert(B[i]);
            
        for(int i = 0; i < N; i++){
            if(set.find(A[i]) != set.end()) {
                auto x = lower_bound(LIS.begin(), LIS.end(), A[i]);
                if(x == LIS.end()) 
                    LIS.push_back(A[i]);
                else
                    *x = A[i];
            }
        }
        return N + M - 2*LIS.size();
    }
};