#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, q;
vector<ll> nums;

struct bit{
    vector<ll> bt;
    void init(){
        bt.resize(n+1, 0);
    }
    void update(ll id, ll val){
        val = val - query(id, id);
        while(id <= n){
            bt[id] += val;
            id += id & (-id);
        }
    }
    ll query(ll i){
        ll resp = 0;
        while(i){
            resp += bt[i];
            i -= i & (-i);
        }
        return resp;
    }
    ll query(ll l, ll r){
        return query(r) - query(l-1);
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    bit tree;
    tree.init();
    ll op, l, r;
    for (int i = 0; i < n; i++){
        cin >> op;
        tree.update(i+1, op);
    }
    for (int i = 0; i < q; i++){
        cin >> op >> l >> r;
        if(op == 1) tree.update(l, r);
        else cout << tree.query(l, r) << "\n";
    }
    
    
}