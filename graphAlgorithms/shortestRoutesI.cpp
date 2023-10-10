#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> adj[n+1];
    for (int i = 0; i < m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    priority_queue<pair<ll, ll>> pq;
    vector<ll> dist(n+1, 1e18);
    pq.push({0, 1});
    while(!pq.empty()){
        ll v = pq.top().second, w = -(pq.top().first);
        pq.pop();
        if(dist[v] < w) continue;
        dist[v] = w;
        for (auto ch : adj[v])if(dist[ch.first] > w+ch.second){
            dist[ch.first] = w+ch.second;
            pq.push({-(w+ch.second), ch.first});
        }
    }
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << "\n";
    return 0;
}