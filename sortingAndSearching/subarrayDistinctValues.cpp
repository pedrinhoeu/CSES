#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n), ac(n+1);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    map<ll, ll> mp;
    ll l = 0, r = 0, at = 0, resp = 0;

    while(r < n){
        mp[nums[r]]++;
        if(mp[nums[r]] == 1) at += 1;
        r++;

        while (at > k){
            if(mp[nums[l]] == 1) at -= 1;
            mp[nums[l]]--;
            l++;
        }
        resp += r-l;
    }
    cout << resp << "\n";
}