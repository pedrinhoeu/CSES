#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, som=0;
    cin >> n;

    for (long long i = 1 ; i <= n ; i++) {
      som += i;
    }
    if(som%2 == 0){
        cout << "YES" << endl;
        if(n%2 == 0){
            cout << n/2 << endl;
            for (int i = 1; i <= n/4; i++){
                cout << i << " " << n+1-i << " ";
            }
            cout << endl;
            cout << n/2 << endl;
            for (int i = (n/4) + 1; i <= n/2; i++){
                cout << i << " " << n+1-i << " ";
            }
            cout << endl;
        }
        else{
            cout << n/2 << endl;
            for (int i = 1; i <= n/4; i++){
                cout << i << " " << n-i << " ";
            }
            cout << n << endl;
            cout << 1 + n/2 << endl;
            for (int i = (n/4) + 1; i <= n/2; i++){
                cout << i << " " << n-i << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}