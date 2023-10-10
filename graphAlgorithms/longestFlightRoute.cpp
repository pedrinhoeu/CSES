#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n+1);
    for (int i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<ll> dist(n+1), volta(n+1);
    vector<bool> visi(n+1);
    queue<array<ll, 3>> pq;
    pq.push({1, 1, 0});
    while (!pq.empty()){
        ll v = pq.front()[1], w = pq.front()[0], p = pq.front()[2];
        pq.pop();
        if(dist[v] > w) continue;
        dist[v] = w;
        volta[v] = p;
        visi[v] = true;
        for (auto ch: adj[v])if(p != ch) pq.push({w+1, ch, v});
    }
    if(dist[n] == 0){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << dist[n] << "\n";
    vector<ll> temp;
    ll t = n;
    while(t != 0){
        temp.push_back(t);
        t = volta[t];
    }
    reverse(temp.begin(), temp.end());
    for(auto i: temp) cout << i << " ";
    cout << "\n";
}