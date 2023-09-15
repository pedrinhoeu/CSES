#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, q, a;
    cin >> n >> q;
    vector<ll> nums(n+1);
    nums[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a;
        nums[i] = nums[i-1] + a;
    }
    ll l, r;
    for (int i = 0; i < q; i++){
        cin >> l >> r;
        cout << nums[r] - nums[l-1] << "\n";
    }
    
}