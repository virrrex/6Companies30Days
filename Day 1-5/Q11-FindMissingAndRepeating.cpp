#include <bits/stdc++.h>
using namespace std;

//  Time Complexity: O(n)   Space Complexity: O(1)
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans = new int[2];
        int xor1 = 0;
        for(int i=0; i<n; i++)
            xor1 ^= arr[i];
        for(int i=1; i<=n; i++)
            xor1 ^= i;
        // now xor1 has value = (missing ^ repeating)
        
        // get right-most set bit
        int set_bit = xor1 & ~(xor1-1);
        int x = 0, y = 0;
        for(int i=0; i<n; i++){
            if(set_bit & arr[i])
                x ^= arr[i];
            else 
                y ^= arr[i];
        }
        for(int i=1; i<=n; i++){
            if(set_bit & i)
                x ^= i;
            else 
                y ^= i;
        }
        bool notFound = true;
        for(int i=0; i<n; i++)
            if(arr[i] == y){
                notFound = false;
                break;
            }
        if(notFound) swap(x,y);
        ans[0] = y; ans[1] = x;
        return ans;
    }
};