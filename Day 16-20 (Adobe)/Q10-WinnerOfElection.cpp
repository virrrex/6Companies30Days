#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string, int> votes;
        for(int i = 0; i < n; i++) 
            votes[arr[i]]++;

        unordered_map<int, vector<string>> rank;
        int max_vote = 0;
        for(auto candidate: votes) {
            if(candidate.second >= max_vote) {
                max_vote = candidate.second;
                rank[max_vote].push_back(candidate.first);
            }
        }
        sort(rank[max_vote].begin(), rank[max_vote].end());
        return {rank[max_vote][0], to_string(max_vote)};
    }
};