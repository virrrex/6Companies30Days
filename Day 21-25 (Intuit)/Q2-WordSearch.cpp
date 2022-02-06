#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findWord(int i, int j, int index, vector<vector<char>>& board, string& word, vector<vector<int>>& visited) {
        if(visited[i][j]) return false;
        if(index == word.size()) return true;
        visited[i][j] = 1;
        // up
        if(i > 0 && word[index] == board[i-1][j]) {
            if(findWord(i-1, j, index + 1, board, word, visited)) 
                return true;
        }
        // down
        if(i < board.size()-1 && word[index] == board[i+1][j]) {
            if(findWord(i+1, j, index + 1, board, word, visited)) 
                return true;
        }
        // left
        if(j > 0 && word[index] == board[i][j-1]) {
            if(findWord(i, j-1, index + 1, board, word, visited)) 
                return true;
        }
        // right
        if(j < board[0].size()-1 && word[index] == board[i][j+1]) {
            if(findWord(i, j+1, index + 1, board, word, visited)) 
                return true;
        }
        visited[i][j] = 0;
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int height = board.size();
        int width = board[0].size();
        
        vector<vector<int>> visited(height, vector<int>(width, 0));
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                if(board[i][j] == word[0] && findWord(i, j, 1, board, word, visited))
                    return true;
            }
        }
        
        return false;
    }
};