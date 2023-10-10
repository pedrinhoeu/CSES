#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> floyd(n+1, vector<ll>(n+1, 1e18));
    for (int i = 0; i < m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        floyd[u][u] = 0;
        floyd[v][v] = 0;
        floyd[u][v] = min(floyd[u][v], w);
        floyd[v][u] = min(floyd[v][u], w);
    }
    for (int k = 1; k <= n; k++)for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
    for (int i = 0; i < q; i++){
        ll u, v;
        cin >> u >> v;
        if(floyd[u][v] >= 1000000000000000000) floyd[u][v] = -1;
        cout << floyd[u][v] << "\n";
    }
    
    return 0;
}