#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2*1e5 + 10;
vector<int> adj[N];
int dist[N];

ll dfs(ll v, ll p, ll d){
    dist[v] = d;
    ll resp = v, temp;
    for(auto ch: adj[v]) if(ch != p){
        temp = dfs(ch, v, d+1);
        if(dist[resp] < dist[temp]) resp = temp;
    }
    return resp;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll A = dfs(1, 0, 0);
    ll B = dfs(A, 0, 0);
    cout << dist[B] << "\n";
}