#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
bool veri(ll val, vector<ll> &nums){
    ll resp = 1, at = 0;
    for (int i = 0; i < n; i++){
        if(nums[i] > val) return false;
        if(nums[i] + at <= val) at += nums[i];
        else{
            resp++;
            at = nums[i];
        }
    }
    if(resp > k) return false;
    return true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    ll resp = 1e18, l = 0, r = 1e18;
    while(l <= r){
        ll mid = (l+r)/2;
        if(veri(mid, nums)){
            resp = min(resp, mid);
            r = mid - 1; 
        }
        else l = mid + 1;
    }
    
    cout << resp << "\n";
}