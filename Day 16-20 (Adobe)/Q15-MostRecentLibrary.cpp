#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; cin >> n;
    vector<vector<int>> lib(n);

    for (int i=0; i<n; i++) {
        string version;
        cin >> version;
        lib[i].push_back(0);
        for(char c: version) {
            if(c == '.') 
                lib[i].push_back(0);
            else
                lib[i].back() =  lib[i].back()*10 + c - '0';
        }
    }
    sort(lib.begin(), lib.end());
    bool dot = false;

    for(auto n: lib.back()) {
        if(dot) cout << ".";
        cout << n;
        dot = true;
    }

    return 0;
}