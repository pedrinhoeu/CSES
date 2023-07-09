#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, resp = 1;
    cin >> n;
    for (int i = 0; i < n; i++){
        resp = (resp*2)%1000000007;
    }
    
    cout << resp << "\n";
    
}