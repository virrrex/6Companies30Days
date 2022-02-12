#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &piles, int h, int speed){
        int sum = 0;
        for(int i=0; i<piles.size(); i++){
            sum += (piles[i] / speed);
            if(piles[i] % speed) sum++;
            if(sum > h) return false;
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1e9;
        while(low <= high){
            int mid = (low+high) >> 1;
            if(isPossible(piles, h, mid))
                high = mid-1;
            else 
                low = mid+1;
        }
        return low;
    }
};