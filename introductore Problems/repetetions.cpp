#include <bits/stdc++.h>

using namespace std;

int main(){
    string n;
    cin >> n;
    long long m=1, s=0, d=1;
    while (d < n.length()){
        if(n[s] == n[d]){
            d += 1;
        }
        else{
            m = max(d-s, m);
            s = d;
            d = s+1;
        }
    }
    m = max(d-s, m);
    cout << m << "\n";
}