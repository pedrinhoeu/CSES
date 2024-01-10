#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t;
    cin >> t;
    while(t--){
        ll a;
        cin >> a;
        a;
        ll temp = 0, tam = 0;
        while(temp < a){
            temp += 9*(10*tam)*(max(tam, ll(1)));
            tam++;
        }
        a -= (tam-1);
        ll n = (tam-1) + a/(tam);
        cout << n << "\n";
    }
}