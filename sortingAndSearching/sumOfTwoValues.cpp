#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k, a;
    cin >> n >> k;
    multiset<pair<ll, ll>> nums;
    vector<ll> nu;
    for (int i = 0; i < n; i++){
        cin >> a;
        nums.insert({a, i+1});
        nu.push_back(a);
    }
    a = 1;
    for (int i = 0; i < n; i++){
        auto id = nums.lower_bound({nu[i], i+1});
        nums.erase(id);
        auto idx = nums.lower_bound({k - nu[i], 0});
        if(idx != nums.end() && (*idx).first == k - nu[i]){
            a = 0;
            cout << min((*idx).second, (*id).second) << " " << max((*idx).second, (*id).second) << "\n";
            break;
        }
    }
    if(a){
        cout << "IMPOSSIBLE\n";
    }
    
}