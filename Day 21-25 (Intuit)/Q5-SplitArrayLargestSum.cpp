#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &nums, int cuts, int max){
        int sum = 0;
        for(int num: nums){
            if(num > max) 
                return false;
            else if(sum + num <= max)
                sum += num;
            else{
                cuts--;
                sum = num;
                if(cuts < 0)
                    return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int low = nums[0], high = 0;
        for(int i: nums){
            low = max(low, i);
            high += i;
        }
        while(low <= high){
            int mid = (low + high) >> 1;
            if(isPossible(nums, m-1, mid))
                high = mid-1;
            else 
                low = mid+1;
        }
        return low;
    }
};