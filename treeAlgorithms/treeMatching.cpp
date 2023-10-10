#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
vector<int> adj[N];
int veri[N];
int resp = 0;

void dfs(int v, int p){
    for(auto ch: adj[v]) if(ch != p){
        dfs(ch, v);
        if(!veri[ch] && !veri[v]){
            veri[ch] = 1;
            veri[v] = 1;
            resp++;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n-1; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << resp << "\n";
}