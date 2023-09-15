#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, q;
    cin >> n >> q;
    vector<ll> nums(n+1);
    nums[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> nums[i];
        nums[i] ^= nums[i-1];
    }
    ll a, b;
    for (int i = 0; i < q; i++){
        cin >> a >> b;
        cout << (nums[a-1] ^ nums[b]) << "\n";
    }
    
}