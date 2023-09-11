#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
struct seg{
    vector<ll> st;
    void init(){
        st.resize(n*4, 0);
        build(1, n, 1);
    }
    void build(ll l, ll r, ll node){
        if(l == r){
            st[node] = 1;
            return;
        } 
        ll mid = (l+r)/2;
        build(l, mid, node*2);
        build(mid+1, r, node*2+1);
        st[node] = st[node*2] + st[node*2+1];
    }
    ll querry(ll l, ll r, ll node, ll val){
        if(l == r){
            st[node] = 0;
            return l;
        } 
        ll mid = (l+r)/2, q;
        if(val <= st[node*2]){
            q = querry(l, mid, node*2, val);
        }
        else{
            q = querry(mid+1, r, node*2+1, val-st[node*2]);
        }
        st[node] = st[node*2] + st[node*2+1];
        return q;
    }
    void prin(){
        for(auto i: st){
            cout << i << " ";
        }
        cout << "\n";
    }
};

int main(){
    cin >> n >> k;
    seg tree;
    tree.init();
    ll val = (k%n)+1, qnt = n;
    for (int i = 0; i < n; i++){
        val %= qnt;
        if(val == 0) val = qnt;
        cout << tree.querry(1, n, 1, val) << " ";
        val += k;
        qnt--;
    }
}