#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> s;
        if(!root) return s;

        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curNode = q.front();
            q.pop();
            if(curNode == NULL) s.push_back(-1);
            else s.push_back(curNode->data);
            if(curNode != NULL){
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       if(A.size() == 0) return NULL;
        int i=0;
        Node *root = new Node(A[i++]);
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node *node = q.front();
            q.pop();

            int str = A[i++];
            if(str == -1)
                node->left = NULL;
            else {
                Node* leftNode = new Node(str);
                node->left = leftNode;
                q.push(leftNode);
            }

            str = A[i++];
            if(str == -1)
                node->right = NULL;
            else {
                Node* rightNode = new Node(str);
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }

};