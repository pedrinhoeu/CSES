#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    ll som = 0, m = 0, a;
    for (int i = 0; i < n; i++){
        cin >> a;
        m = max(m, a);
        som += a;
    }
    cout << max(som, m*2) << "\n";
}