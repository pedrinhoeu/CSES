#include <bits/stdc++.h>

using namespace std;

int main(){
    string n;
    long long result = 0;
    vector<string> resps;
    cin >> n;
    sort(n.begin(), n.end());
    for (int i = 0; i < 30; i++){
        cout << next_permutation(n.begin(), n.end()) << endl;
    }
    
    
    
}