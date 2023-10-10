#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2*1e5 + 10, LOG = 30;
ll anc[N][LOG];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, q;
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) cin >> anc[i+1][0]; 

    for (int i = 1; i < LOG; i++) for (int j = 1; j <= n; j++)anc[j][i] = anc[anc[j][i-1]][i-1];

    for (int g = 0; g < q; g++){
        ll v, k;
        cin >> v >> k;
        for (int i = 0; i < LOG; i++) if(k & (1 << i)) v = anc[v][i];
        cout << v << "\n";
    }    
}