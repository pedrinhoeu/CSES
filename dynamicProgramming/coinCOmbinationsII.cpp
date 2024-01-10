#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> dp(x+1);
    dp[0] = 1;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    for (int i = 0; i < n; i++){
        for (int w = 1; w <= x; w++) {
			if (w - nums[i] >= 0) {
				dp[w] += dp[w - nums[i]];
				dp[w] %= 1000000007;
			}
		}
    }
    cout << dp[x] << "\n";
}