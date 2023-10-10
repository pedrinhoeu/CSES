#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m;
vector<int> adj[N];

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    vector<int> dist(n+1, -1);
    queue<array<int, 3>> q;
    q.push({1, 1, 0});
    dist[1] = -1;
    while(!q.empty()){
        int v = q.front()[1], w = q.front()[0], p = q.front()[2];
        q.pop();
        if(v == n){
            dist[v] = p;
            vector<int> resp;
            resp.push_back(n);
            while(v != 1){
                resp.push_back(dist[v]);
                v = dist[v];
            }
            cout << w << "\n";
            for (int i = w-1; i >= 0; i--) cout << resp[i] << " ";
            cout << "\n";
            return 0;
            
        }
        if(dist[v] != -1) continue;
        dist[v] = p;
        for (auto ch: adj[v]) if(dist[ch] == -1) q.push({w+1, ch, v});
        
    }
    cout << "IMPOSSIBLE\n";
}