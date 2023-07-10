#include <bits/stdc++.h>

using namespace std;

int main(){
    string n;
    long long result = 0;
    vector<string> resps;
    cin >> n;
    sort(n.begin(), n.end());
    resps.push_back(n);
    while(next_permutation(n.begin(), n.end())){
        resps.push_back(n);
    }
    cout << resps.size() << endl;
    for (auto i : resps){
        cout << i <<  "\n";
    }
    
    
    
}