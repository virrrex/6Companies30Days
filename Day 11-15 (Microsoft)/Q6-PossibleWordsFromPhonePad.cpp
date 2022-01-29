#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        if (!N) return {};
		vector<string> result;
        result.push_back("");
        
        for(int i=0; i<N; i++) {
            vector<string> tmp;
            for(auto candidate: pad[a[i]]) {
                for(auto s: result) {
                    tmp.push_back(s + candidate);
                }
            }
            result.swap(tmp);
        }
        sort(result.begin(), result.end());
        return result;
    }
};

// lc 17