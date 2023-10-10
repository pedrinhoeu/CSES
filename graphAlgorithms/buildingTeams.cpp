#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int times[N];
vector<int> adj[N];
bool veri = true;

void salv(int i, int op){
    if(times[i] != 0 && times[i] != op) veri = false;
    if(times[i]) return;
    times[i] = op;
    for (auto ch: adj[i]) salv(ch, ((op-1)^1) + 1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++){
        if(!times[i]) salv(i, 1);
    }

    if(!veri){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) cout << times[i] << " ";
    
    cout << "\n";
}