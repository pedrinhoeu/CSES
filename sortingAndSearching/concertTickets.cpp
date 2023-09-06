#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, q, a;
    cin >> n >> q;
    multiset<ll> nums;
    for (int i = 0; i < n; i++){
        cin >> a;
        nums.insert(a);
    }    
    for (int i = 0; i < q; i++){
        cin >> a;
        auto it = nums.upper_bound(a);
        if(nums.begin() == it){
            cout << -1 << "\n";
        }
        else{
            --it;
            nums.erase(it);
            cout << *it << "\n";
        }
    }
}