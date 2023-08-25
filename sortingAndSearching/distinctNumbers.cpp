#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    ll ans = 0, ant = -1;
    for (int i = 0; i < n; i++){
        if(nums[i] != ant) ans++;
        ant = nums[i];
    }
    cout << ans << "\n";
}