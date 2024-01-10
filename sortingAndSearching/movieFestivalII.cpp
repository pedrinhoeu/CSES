#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    multiset<ll> pq;
    vector<pair<ll, ll>> nums(n);
    for (int i = 0; i < k; i++) pq.insert(0);
    ll resp = 0;
    for (int i = 0; i < n; i++) cin >> nums[i].second >> nums[i].first;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n; i++){
        auto temp = pq.upper_bound(nums[i].second);
        if(temp != pq.begin()){
            resp++;
            pq.erase(--temp);
            pq.insert(nums[i].first);
        }
    }
    cout << resp << "\n";
}