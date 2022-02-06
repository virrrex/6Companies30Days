#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &weights, int days, int t){
        int sum = 0, ct = 0;
        for(int i=0; i<weights.size(); i++){
            if(sum + weights[i] <= t)
                sum += weights[i];
            else {
                sum = weights[i];
                if(sum > t) return false;
                ct++;
                if(ct > days) return false;
            }
        }
        if(sum <= t) ct++;
        if(ct > days) return false;
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1, high = 0;
        for(int i: weights)
            high += i;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(isPossible(weights, days, mid))
                high = mid-1;
            else 
                low = mid+1;
        }
        return low;
    }
};