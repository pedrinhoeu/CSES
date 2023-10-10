#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> resp;
vector<vector<ll>> adj;

ll dfs(ll v, ll p){
    ll temp = 0;
    for (auto i: adj[v])if(i != p){
        temp += dfs(i, v);
    }
    resp[v] = temp;
    return temp+1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    resp.resize(n+1);
    adj.resize(n+1);
    for (int i = 1; i < n; i++){
        ll v;
        cin >> v;
        adj[i+1].push_back(v);
        adj[v].push_back(i+1);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)cout << resp[i] << " ";
    cout << "\n";
}