#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5+10;
vector<ll> resp, visi(N), comp(N);
vector<vector<ll>> adj(N);

void dfs(ll v){
    if(visi[v]) return;
    comp[v]--;
    if(comp[v] > 0) return;
    visi[v] = 1;
    resp.push_back(v);
    for (auto ch: adj[v]) dfs(ch);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        comp[v]++;
    }
    for (int i = 1; i <= n; i++)if(comp[i] == 0) dfs(i);
    if(resp.size() != n) cout << "IMPOSSIBLE\n";
    else for (auto i: resp) cout << i << " ";
    cout << "\n";
    return 0;
}