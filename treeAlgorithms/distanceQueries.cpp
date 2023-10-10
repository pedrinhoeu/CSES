#include <bits/stdc++.h>
using namespace std;

int n, q;
const int N = 2e5+10, LOG = 30;
vector<int> adj[N];
int anc[N][LOG+1], dist[N];

void dfs(int v, int p, int d){
    dist[v] = d;
    for (int i = 1; i <= LOG; i++) anc[v][i] = anc[anc[v][i-1]][i-1];

    for (auto ch: adj[v])if(ch != p){
        anc[ch][0] = v;
        dfs(ch, v, d+1);
    }  
}
int lca(int a, int b){
    // for (int i = 1; i <= n; i++){
    //     for (int j = 0; j <= LOG; j++){
    //         cout << anc[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    int resp = dist[a] + dist[b];
    if(dist[a] < dist[b]) swap(a, b);
    for (int i = LOG; i >= 0; i--){
        if(dist[a] - dist[b] >= (1 << i)){
            a = anc[a][i];
        }
    }
    
    if(a == b) return resp - (2*dist[a]);
    for (int i = LOG; i >= 0; i--){
        if(anc[a][i] != anc[b][i]){
            
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    return resp - (2*dist[anc[a][0]]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;

    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 1);
    for (int i = 0; i < q; i++){
        int v, u;
        cin >> v >> u;
        cout << lca(v, u) << "\n";
    }
    
}