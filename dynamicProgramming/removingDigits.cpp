#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<ll> dp(n+1, 1e9);
    dp[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        ll temp = 1;
        while(temp <= i){
            dp[i] = min(dp[i], dp[i - (i/temp)%10] + 1);
            temp *= 10;
        }
    }
    cout << dp[n] << "\n";
}