#include <bits/stdc++.h>
using namespace std;

int n, q;
const int N = 2e5+10, LOG = 30;
vector<int> adj[N];
int anc[N][LOG], dist[N];

void dfs(int v, int p, int d){
    dist[v] = d;
    
    for (int i = 1; i < LOG; i++) anc[v][i] = anc[anc[v][i-1]][i-1];

    for (auto ch: adj[v]){
        anc[ch][0] = v;
        dfs(ch, v, d+1);
    }  
}
int lca(int v, int k){
    // for (int i = 1; i <= n; i++){
    //     for (int j = 0; j <= LOG; j++){
    //         cout << anc[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    for (int i = LOG; i >= 0; i--){
        if((1 << i) & k){
            v = anc[v][i];
        }
    }

    if(v == 0) v = -1;
    return v;
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;

    for (int i = 2; i <= n; i++){
        int u;
        cin >> u;
        adj[u].push_back(i);
    }
    dfs(1, 0, 1);
    for (int i = 0; i < q; i++){
        int v, x;
        cin >> v >> x;
        cout << lca(v, x) << "\n";
    }
    
}