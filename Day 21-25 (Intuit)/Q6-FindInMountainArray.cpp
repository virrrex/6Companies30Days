#include <bits/stdc++.h>
using namespace std;

class MountainArray {
    public:
    int get(int index);
    int length();
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = 0, r = mountainArr.length() - 1;
        while (peak < r) {
            int m = (peak + r) / 2;
            if (mountainArr.get(m) > mountainArr.get(m + 1)) r = m;
            else peak = m + 1;
        }
        int i = bSearch(mountainArr, target, 0, peak);
        return i != -1 ? i : bSearch(mountainArr, target, peak + 1, mountainArr.length() - 1, false);
    }
    int bSearch(MountainArray& arr, int t, int l, int r, bool asc = true) {
        while (l <= r) {
            int m = (l + r) >> 1;
            int val = arr.get(m);
            if (val == t) return m;
            if (asc == val < t) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};