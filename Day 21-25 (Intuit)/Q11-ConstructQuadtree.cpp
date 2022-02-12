#include <bits/stdc++.h>
using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, grid.size(), 0, grid.size()) ;
    }
    
    Node* solve(vector<vector<int>>& grid, int left, int right, int up, int down) {
        bool allSame = true ;
        for(int i=up ; i<down ; i++) {
            for(int j=left ; j<right ; j++) {
                if(grid[i][j]!=grid[up][left]) {
                    allSame = false ;
                    break ;
                }
            }
        }
        if(allSame) return new Node(grid[up][left], true) ;
        Node* ans = new Node() ;
        int midLR = (left+right)/2 ;
        int midUD = (up+down)/2 ;
        ans->topLeft = solve(grid, left, midLR, up, midUD) ;
        ans->topRight = solve(grid, midLR, right, up, midUD) ;
        ans->bottomLeft = solve(grid, left, midLR, midUD, down) ;
        ans->bottomRight = solve(grid, midLR, right, midUD, down) ;
        return ans ;
    }
};