#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    ll a;
    multiset<ll> nums;
    for (int i = 0; i < n; i++){
        cin >> a;
        auto it = nums.upper_bound(a);
        if (it == nums.end()) nums.insert(a);
		else{
			nums.erase(it);
			nums.insert(a);
		}
    }
    cout << nums.size() << "\n";
}