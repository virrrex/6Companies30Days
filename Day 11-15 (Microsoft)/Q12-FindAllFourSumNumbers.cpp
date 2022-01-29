#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> res;
        if(arr.empty())
            return res;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int target2 = k - arr[j] - arr[i];
                int front  = j+1;
                int back = n-1;

                while(front < back){
                    int twoSum = arr[front] + arr[back];
                    if(twoSum < target2) front++;
                    else if(twoSum > target2) back--;
                    else {
                        vector<int> quadruplet(4,0);
                        quadruplet[0] = arr[i];
                        quadruplet[1] = arr[j];
                        quadruplet[2] = arr[front];
                        quadruplet[3] = arr[back];
                        res.push_back(quadruplet);

                        while(front < back && arr[front] == quadruplet[2])
                            ++front;
                        while(front < back && arr[back] == quadruplet[3])
                            --back;
                    }
                }
                while(j+1 < n && arr[j+1] == arr[j])
                    ++j;
            }
            while(i+1 < n && arr[i+1] == arr[i])
                ++i;
        }
        return res;
    }
};