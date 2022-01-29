#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
        stack<int> st;
        int index = 0;
        vector<int> ans;
        while(n--){
            int p = price[index++];
        
            while(!st.empty() && price[st.top()] <= p)
                st.pop();
            
            if(st.empty()){
                st.push(index - 1);
                ans.push_back(index);
            }
            else {
                int a = index - 1 - st.top();
                st.push(index - 1);
                ans.push_back(a);
            }
        }
        return ans;
    }
};