#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    cin >> n;
    map<ll, ll> mud;
    vector<array<ll, 2>> ops;
    vector<ll> nums;
    ll a, b;
    for (ll i = 0; i < n; i++){
        cin >> a >> b;
        ops.push_back({a, b});
        nums.push_back(a);
        nums.push_back(b);
    }
    sort(nums.begin(), nums.end());
    ll comp = 0, ant = 0;
    for (ll i = 0; i < n*2; i++){
        if(nums[i] != ant){
            mud[nums[i]] = comp;
            ant = nums[i];
            comp++;
        }
    }
    vector<ll> horas(comp+1, 0);
    for (ll i = 0; i < n; i++){
        horas[mud[ops[i][0]]] += 1;
        horas[mud[ops[i][1]]] -= 1;
    }
    ll resp = 0, som=0;
    for(ll i = 0; i < comp+1; i++){
        som += horas[i];
        resp = max(som, resp);
    }
    cout << resp << "\n";
    return 0;
}