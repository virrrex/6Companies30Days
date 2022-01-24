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

class Solution {
  public:
    int findMaxDistance(map<Node*, Node*> &mp, Node* start){
        queue<Node*> q;
        q.push(start);
        map<Node*, int> vis;
        vis[start] = 1;
        int maxi = 0;
        while(!q.empty()){
            int sz = q.size();
            int flag = 0;
            for(int i=0; i<sz; i++){
                auto node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    flag = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    flag = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                if(mp[node] && !vis[mp[node]]){
                    flag = 1;
                    vis[mp[node]] = 1;
                    q.push(mp[node]);
                }
            }
            if(flag) maxi++;
        }
        return maxi;
    }

    Node* bfsToMapParent(Node* root, map<Node*, Node*> &mp, int target){
        queue<Node*> q;
        q.push(root);
        Node* res;
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            if(node->data == target) res = node;
            if(node->left){
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*, Node*> mp;
        Node* start = bfsToMapParent(root, mp, target);
        int maxi = findMaxDistance(mp, start);
        return maxi;
    }
};