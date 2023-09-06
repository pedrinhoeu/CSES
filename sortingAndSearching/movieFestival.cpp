#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i].second >> nums[i].first;
    }
    sort(nums.begin(), nums.end());
    ll h = 0, resp = 0;
    for (int i = 0; i < n; i++){
        if(h <= nums[i].second){
            resp++;
            h = nums[i].first;
        }
    }
    cout << resp << "\n";
}