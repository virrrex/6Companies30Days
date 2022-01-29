#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int, int> mp;
        for(int i: nums)
            mp[i % k]++;
        
        // if divisible by 6 numbers are odd, pair not possible
        if(mp[0] & 1)
            return false;
        
        // checking matching pairs for remaining numbers
        for(int i=1; i<k; i++){
            if(mp[i] != mp[k-i])
                return false;
        }
        return true;
    }
};