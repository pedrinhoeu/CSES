#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<array<ll, 2>>> adj(n+1);
    for (int i = 0; i < m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<vector<ll>> dist(n+1, vector<ll>(k, 1e18));
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        ll v = pq.top().second, w = -pq.top().first;
        pq.pop();
        bool veri = false;
        for (int i = 0; i < k; i++)if(dist[v][i] > w){
            dist[v][i] = w;
            veri = true;
            break;
        }
        if(!veri) continue;
        for (auto ch: adj[v]){
            pq.push({-(w+ch[1]), ch[0]});
        }
    }
    for (auto i: dist[n]) cout << i << " ";
    cout << "\n";
}