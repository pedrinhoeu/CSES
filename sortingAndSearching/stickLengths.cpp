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
    ll resp = 0, comp = nums[n/2];
    for (int i = 0; i < n; i++){
        resp += abs(comp - nums[i]);
    }
    cout << resp << "\n";   
}