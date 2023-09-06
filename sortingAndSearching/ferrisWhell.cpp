#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    ll resp = 0, l = 0, r = n-1;
    sort(nums.begin(), nums.end());
    
    while(l <= r){
        resp++;
        if(nums[l] + nums[r] <= k){
            l++;
        }
        r--;
    }
    cout << resp << "\n";
}