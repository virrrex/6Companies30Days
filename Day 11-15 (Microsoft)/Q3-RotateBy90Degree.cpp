#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int n = matrix.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++)
            swap(matrix[i][j], matrix[j][i]);
    }
    
    for(int i=0; i<n-i-1; i++)
        swap(matrix[i], matrix[n-i-1]);
}