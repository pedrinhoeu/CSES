#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, q, INF = 1e18;
vector<ll> nums(n);

struct SEG{
    vector<ll> st;
    void init(){
        st.resize(4*n, INF);
        build(1, n, 1);
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
    ll querry(ll l, ll r, ll node, ll sta, ll end){
        if(l > end || r < sta) return INF;
        if(l >= sta && r <= end) return st[node];
        ll mid = (l+r)/2;
        ll q1 = querry(l, mid, node*2, sta, end), q2 = querry(mid+1, r, node*2+1, sta, end);
        return min(q1, q2);
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    nums.resize(n);
    for (int i = 0; i < n; i++)cin >> nums[i];
    ll l, r;
    SEG tree;
    tree.init();
    for (int i = 0; i < q; i++){
        cin >> l >> r;
        cout << tree.querry(1, n, 1, l, r) << "\n";
    }
}