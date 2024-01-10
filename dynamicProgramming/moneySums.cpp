#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<ll> m(n);
    for(int i = 0; i < n; i++) cin >> m[i];
    vector<ll> comp (1e6);

    comp[0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 1e6-1; j >= 0; j--){
            if(comp[j]) comp[m[i] + j] = 1;
        }
    } 
    ll resp = 0;
    for(int j = 1; j < 1e6 ; j++) resp += comp[j];
    cout << resp << "\n";
    for(int j = 1; j < 1e6 ; j++)if(comp[j]) cout << j << " ";
    cout << "\n";
}