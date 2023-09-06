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
    ll sum = -1e18, bst = -1e18;
    for (int i = 0; i < n; i++){
        sum = max(nums[i], sum + nums[i]);
        bst = max(bst, sum);
    }
    cout << bst << "\n";
}