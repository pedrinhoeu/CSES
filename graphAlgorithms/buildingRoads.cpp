#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 2*1e5 + 10;
int pai[N], peso[N];

int find(int x){
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(peso[b] > peso[a]){
        pai[a] = b;
        return;
    } 
    pai[b] = a;
    if(peso[a] == peso[b])peso[a]++;
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) pai[i] = i;
    
    for (int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        if(find(v) != find(u)) join(v, u);
        
    }

    vector<pair<int, int>> resp;
    for (int i = 2; i <= n; i++){
        if(find(1) != find(i)){
            join(1, i);
            resp.push_back({1, i});
        }
    }
    cout << resp.size() << "\n";
    for (auto i: resp)cout << i.first << " " << i.second << "\n";
}