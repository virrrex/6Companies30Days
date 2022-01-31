#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        vector<int> ans(2,-1);
        long long  sum = 0;
        int left = 0;
        int right = 0;
        while(right < n) {
            if((sum + arr[right]) == s) {
                ans[0] = left + 1;
                ans[1] = right + 1;
                break ;
            }
            else if((sum + arr[right]) < s) {
                sum += arr[right];
                right++;
            }
            else {
                sum -= arr[left];
                left++;
            }
        }
        if(ans[0] == -1  && ans[1] == -1) 
             ans.pop_back();
        
        return ans;
    }
};