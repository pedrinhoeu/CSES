#include <bits/stdc++.h>
using namespace std;

const int N = 2*1e5+10;
bool veri = false;
int visi[N], n, m;
stack<int> q;
vector<int> adj[N];

void dfs(int v, int p){
    if(veri) return;
    if(visi[v]){
        if(q.size() > 1){
            veri = true;
            vector<int> temp;
            int resp = 1, last = 0;
            while(!q.empty() && last != v){
                temp.push_back(q.top());
                resp++;
                last = q.top();
                q.pop();
            }
            cout << resp << "\n" << v << " ";
            for(auto i: temp) cout << i << " ";
            cout << "\n";
        }
        
    } 
    visi[v] = true;
    q.push(v);
    for (auto ch: adj[v])if(ch != p){
        dfs(ch, v);        
    }
    visi[v] = false;
    if(q.size() > 0) q.pop();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) if(!visi[i] && !veri){
        dfs(i, 0);
    }
    if(!veri)cout << "IMPOSSIBLE\n";
    return 0;
}