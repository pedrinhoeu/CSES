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
    ll resp = 1;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++){
        if(nums[i] > resp){
            break;
        }
        resp += nums[i];
    }
    cout << resp << "\n";
}