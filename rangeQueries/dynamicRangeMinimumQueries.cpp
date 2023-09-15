#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, INF = 1e18, q;
vector<ll> nums;

struct SEG{
    vector<ll> st;
    void init(){
        st.resize(n*4, INF);
    }
    void build(ll l, ll r, ll node){
        if(l == r){
            st[node] = nums[l-1];
            return;
        }
        ll mid = (l+r)/2;
        build(l, mid, node*2);
        build(mid+1, r, node*2+1);
        st[node] = min(st[node*2], st[node*2+1]);
    }
    void update(ll l, ll r, ll node, ll id, ll val){
        if(l == r){
            st[node] = val;
            return;
        }
        ll mid = (l+r)/2;
        if(id <= mid) update(l, mid, node*2, id, val);
        else update(mid+1, r, node*2+1, id, val);
        st[node] = min(st[node*2], st[node*2+1]);
    }

    ll querry(ll l, ll r, ll node, ll sta, ll end){
        if(l > end || r < sta) return INF;
        if(l >= sta && r <= end) return st[node];
        ll mid = (l+r)/2;
        return min(querry(l, mid, node*2, sta, end), querry(mid+1, r, node*2+1, sta, end));
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    ll op, a, b;
    SEG tree;
    tree.init();
    for (int i = 0; i < n; i++){
        cin >> a;
        tree.update(1, n, 1, i+1, a);
    }
    for (int i = 0; i < q; i++){
        cin >> op >> a >> b;
        if(op == 1) tree.update(1, n, 1, a, b);
        else cout << tree.querry(1, n, 1, a, b) << "\n";
    }    
}