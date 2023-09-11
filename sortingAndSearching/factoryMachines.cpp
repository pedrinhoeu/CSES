#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    ll low = 0, hit = 1e18, bst = 0;
    while(low <= hit){
        ll mid = (low+hit)/2, sum = 0;
        for (int i = 0; i < n; i++){
            sum += mid/nums[i];
            if(sum >= k) break;
        }
        if(sum >= k){
            hit = mid - 1;
            bst = mid;
        }
        else{
            low = mid + 1;
        }
    }
    cout << bst << "\n";
}