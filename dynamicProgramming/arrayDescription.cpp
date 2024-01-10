#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    vector<vector<ll>> resp(n, vector<ll>(m+1));

    if(nums[0] == 0){
        for(auto &i: resp[0]) i = 1;
        resp[0][0] = 0;
    } 
    else resp[0][nums[0]] = 1;

    ll mod = 1e9+7;

    for (int i = 1; i < n; i++){
        if(nums[i] == 0)for (int j = 1; j <= m; j++){
            resp[i][j] = resp[i-1][j];
            if(j < m) resp[i][j] += resp[i-1][j+1];
            if(j > 1) resp[i][j] += resp[i-1][j-1];
            resp[i][j] %= mod;
        }
        else{
            resp[i][nums[i]] = resp[i-1][nums[i]];
            if(nums[i] < m) resp[i][nums[i]] += resp[i-1][nums[i]+1];
            if(nums[i] > 1) resp[i][nums[i]] += resp[i-1][nums[i]-1];
            resp[i][nums[i]] %= mod;
        }
        
    }
    ll res = 0;
    if(nums[n-1] == 0) for(auto k: resp[n-1]) res += k;
    else res = resp[n-1][nums[n-1]];
    res %= mod;
    cout << res << "\n";
    
}