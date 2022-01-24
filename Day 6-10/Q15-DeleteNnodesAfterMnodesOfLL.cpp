#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
};

class Solution
{
    public:
    void linkdelete(struct Node *head, int M, int N)
    {
        //Add code here   
        Node* node = head;
        while(node != NULL) {
            for(int i = 1; i < M && node != NULL; i++)
                node = node->next;
            
            if(node == NULL) return;
            Node* ref = node;

            for(int i = 0; i <= N && node != NULL; i++)
                node = node->next;

            ref->next = node;
        }
    }
};