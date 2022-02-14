#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comp(string& a, string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        nth_element(nums.begin(), nums.end()-k, nums.end(), comp);
        return nums[nums.size()-k];
    }
};