#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int low = 0, high = 0, count = 0;
        long long prod = 1;

        for(int i = 0; i < n; i++) {
            high = i;
            
            prod *= a[high];
            count += high - low + 1;
            
            while(prod >= k) {
                prod /= a[low++];
                count -= 1;
            }
        }
        
        return count;
    }
};