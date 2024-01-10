#include <bits/stdc++.h>
using namespace std;
typedef long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> res(n), comp(n+1);
    ll resp = 0;
    for (int i = 0; i < n; i++){
        cin >> res[i];
        if(comp[res[i]-1] == 0) resp++;
        comp[res[i]] = i+1;
    }

    for (int i = 0; i < m; i++){
        ll v, u;
        cin >> v >> u;
        v--;
        u--;
        if(comp[res[v]] > comp[res[u]]) resp--;
        else resp++;
        ll temp = comp[res[v]];
        comp[res[v]] = comp[res[u]];
        comp[res[u]] = temp;
        temp = res[v];
        res[v] = res[u];
        res[u] = temp;
        
        cout << resp << "\n";
    }
    
}