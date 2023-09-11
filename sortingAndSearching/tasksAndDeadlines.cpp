#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> dead(n);
    for (int i = 0; i < n; i++){
        cin >> dead[i].first >> dead[i].second;
    }
    sort(dead.begin(), dead.end());
    ll resp = 0, h = 0;
    for (int i = 0; i < n; i++){
        h += dead[i].first;
        resp += dead[i].second - h;
        
    }
    cout << resp << "\n";
    
}