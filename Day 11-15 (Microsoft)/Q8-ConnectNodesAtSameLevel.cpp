#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
};


class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       if(root == NULL) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            Node* prev = NULL;
            for(int i=0; i<size; i++){
                Node* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(i) prev->nextRight = node;
                prev = node;
            }
            prev->nextRight = NULL;
        }
    }    
      
};