#include <bits/stdc++.h>
using namespace std;

class Node {
    public:

    Node* links[26];
    char value;
    int ends, depth;

    Node(char letter, int d) {
        value = letter;
        ends = 0;
        depth = d;

        for(int i = 0; i < 26; ++i) {
            links[i] = NULL;
        }
    }
};

class Trie {
    public:

    Node* root;

    Trie() {
        root = new Node('/', 0);
    }

    void insert(string& word) {
        Node* node = root;

        for(int i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';

            if(node->links[index] == NULL)
                node->links[index] = new Node(word[i], i + 1);

            node = node->links[index];
        }

        node->ends += 1;
    }
    
    vector<string> wordsWithPrefix(string prefix) {
        Node* node = root;
        vector<string> results;
    
        int N = prefix.length();
        for(int i = 0; i < N; ++i) {
            node = node->links[prefix[i] - 'a'];
            if(node == NULL) return results;
        }
        Node* prefix_end = node;

        stack<Node*> nodes;
        nodes.push(node);
        string stream = "";
        
        while(!nodes.empty()) {
            node = nodes.top();
            nodes.pop();
        
            if(stream.size() > node->depth - prefix_end->depth) {
                stream = stream.substr(0, node->depth - prefix_end->depth);
            }
            
            stream += node->value;
            for(int i = 25; i >= 0; --i) {
                if(node->links[i] != NULL) {
                    nodes.push(node->links[i]);
                }
            }
            
            if(node->ends) {
                results.push_back(prefix + stream.substr(1));
            }
        }

        return results;
    }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie* dict = new Trie();
        for(int i = 0; i < n; ++i) {
            dict->insert(contact[i]);
        }

        vector<vector<string>> ans(s.size());
        
        for(int i = 0; i < s.size(); ++i) {
            vector<string> res = dict->wordsWithPrefix(s.substr(0, i + 1));
            if(res.empty()) {
                ans[i] = {"0"};
            }
            else {
                ans[i] = res;
            }
        }
        return ans;
    }
};