#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        vector<bitset<10>> rowCheck(9), colCheck(9), blockCheck(9);

        for(int r = 0; r < 9; ++r) {
            for(int c = 0; c < 9; ++c) {
                int num = mat[r][c];
                
                if(num && (rowCheck[r].test(num) || colCheck[c].test(num) ||
                    blockCheck[3*(r/3) + c/3].test(num))
                ) return 0;
                
                rowCheck[r].set(num);
                colCheck[c].set(num);
                blockCheck[3*(r/3) + c/3].set(num);
            }
            
        }
        return 1;
    }
};