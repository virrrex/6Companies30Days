#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        // Your code here
        createSumTree(node);
    }
    
    int createSumTree(Node *node) {
        if(node == NULL) return 0;
        
        int left = createSumTree(node->left);
        int right = createSumTree(node->right);
        int curr = node->data;
        node->data = left + right;
        return left + right + curr;
    }
};