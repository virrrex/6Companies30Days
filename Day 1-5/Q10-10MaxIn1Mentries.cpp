#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    vector<int> max10Elements(vector<int> &entries){
        int mx = 10;
        vector<int> result(mx);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int &i: entries){
            minHeap.push(i);
            if(minHeap.size() > mx)
                minHeap.pop();
        }

        for(int i=0; i<mx; i++){
            int top = minHeap.top();
            minHeap.pop();
            result[i] = top;
        }
        return result;
    }
};