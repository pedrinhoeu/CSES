#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    vector<string> comp(n);
    
    for (int i = 0; i < n; i++) cin >> comp[i];
    if (comp[0][0] != '*') dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
			if (comp[i][j] != '*') {
				if (i > 0) dp[i][j] += dp[i-1][j];
                if (j > 0) dp[i][j] += dp[i][j-1];
                dp[i][j] %= 1000000007;
			}
		}
    }
    cout << dp[n-1][n-1] << "\n";
}