#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> dp(x+1);
    vector<ll> price(n), pages(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> pages[i];
    
    for (int i = 0; i < n; i++){
        for (int w = x; w >= 0; w--){
			if(w + price[i] <= x) dp[w+price[i]] = max(dp[w+price[i]], dp[w] + pages[i]);
		}
    }
    cout << dp[x] << "\n";
}