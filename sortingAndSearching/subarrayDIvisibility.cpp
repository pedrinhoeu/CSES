#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++)cin >> nums[i];
    ll resp = 0, at = 0;
    map<ll, ll> soms;
    soms[0] = 1;
    for (auto i: nums){
        at += i;
        resp += soms[(at % n + n) % n];
        soms[(at % n + n) % n]++;
    }
    
    cout << resp << "\n";
}