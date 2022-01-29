#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
//Function to count number of subtrees having sum equal to given sum.

pair<int, int> subtreeSum(Node* root, int x) {

    if(root == NULL) return {0, 0};

    int count = 0;

    pair<int, int> left = subtreeSum(root->left, x);
    pair<int, int> right = subtreeSum(root->right, x);

    count += left.first;
    count += right.first;

    int sum = left.second + right.second + root->data;

    if(sum == x)
        count++;

    return {count, sum};
}

int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	pair<int, int> result = subtreeSum(root, X);
	return result.first;
}