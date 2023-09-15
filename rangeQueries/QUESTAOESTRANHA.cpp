#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, q;

struct SEG{
    vector<ll> st, lz;
    void init(){
        st.resize(4*n, 0);
        lz.resize(4*n, 0);
    }
    void push(ll l, ll r, ll node){
        if(lz[node]){
            if(l == r){
                st[node] += lz[node];
                lz[node] = 0;
                return;
            }
            lz[node*2] += lz[node];
            lz[node*2+1] += lz[node];
            lz[node] = 0;
        }
    }
    void update(ll l, ll r, ll val, ll sta, ll end, ll node){
        push(l, r, node);
        if(l > end || sta > r) return;
        if(l >= sta && end >= r){
            lz[node] += val;
            return;
        }
        ll mid = (l+r)/2;
        update(l, mid, val, sta, end, node*2);
        update(mid+1, r, val, sta, end, node*2+1);
    }
    ll query(ll l, ll r, ll id, ll node){
        push(l, r, node);
        if(l == r) return st[node];
        ll mid = (l+r)/2;
        if(id <= mid) return query(l, mid, id, node*2);
        return query(mid+1, r, id, node*2+1);
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    SEG tree;
    tree.init();
    ll op, l, r, val;
    for (int i = 0; i < n; i++){
        cin >> val;
        tree.update(1, n, val, i+1, i+1, 1);
    }
    for (int i = 0; i < q; i++){
        cin >> op;
        if(op == 1){
            cin >> l >> r >> val;
            tree.update(1, n, val, l, r, 1);
        }
        else{
            cin >> val;
            cout << tree.query(1, n, val, 1) << "\n";
        }
    }
    
    
}