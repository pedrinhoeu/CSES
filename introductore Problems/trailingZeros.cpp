#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, num = 5, resp = 0;
    cin >> n;
    while(num <= n){
        resp += n/num;
        num *= 5;
    }
    
    cout << resp << "\n";
    
}