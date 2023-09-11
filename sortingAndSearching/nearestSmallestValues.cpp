#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct seg{
    vector<ll> st;
    void init(){
        st.resize((1e6)*4, 0);
    }
    void update(ll l, ll r, ll node, ll id, ll val){
        if(l == r){
           st[node] = val;
           return;
        }
        ll mid = (l + r)/2;
        if(id <= mid){
            update(l, mid, node*2, id, val);
        }
        else{
            update(mid+1, r, node*2+1, id, val);
        }
        st[node] = max(st[node*2], st[node*2+1]);
    }
    ll querry(ll l, ll r, ll node, ll dir){
        if(r < dir) return st[node];
        if(l >= dir || l > r) return 0;
        ll mid = (r + l)/2;
        return max(querry(l, mid, node*2, dir), querry(mid+1, r, node*2+1, dir));
    }
};

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> nums(n);

    for (int i = 0; i < n; i++){
        cin >> nums[i].first;
        nums[i].second = i;
    }


    sort(nums.begin(), nums.end());
    ll count = 0, ant = 0;
    for (int i = 0; i < n; i++){
        if(ant != nums[i].first){
            count++;
            ant = nums[i].first;
        }
        nums[i].first = nums[i].second;
        nums[i].second = count;
    }
    sort(nums.begin(), nums.end());
    seg tree;
    tree.init();
    
    for (int i = 0; i < n;){
        ll temp = tree.querry(1, 1e6, 1, nums[i].second);
        cout << temp << " ";
        i++;
        tree.update(1, 1e6, 1, nums[i-1].second, i);
    }
    cout << "\n";
    
    return 0;
}