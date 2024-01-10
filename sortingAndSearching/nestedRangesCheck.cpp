#include <bits/stdc++.h>
using namespace std;
 
bool customSort(const array<int, 3> &a, const array<int, 3> &b) {
    if (a[0] == b[0]) return a[1] > b[1];
    
    return a[0] < b[0];
}
 
struct bit{
    vector<int> bt;
    void init() {bt.resize(1e6+10);}
    int querry(int x){
        int sum = 0;
        for(; x > 0; x -= x&-x)
            sum += bt[x];
        return sum;
    }
    void update(int x){
        for(; x <= 1e6; x += x&-x) bt[x] += 1;
    }
};
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<array<int, 3>> pri(n);
    set<int> ajuda;
    for (int i = 0; i < n; i++){
        cin >> pri[i][0] >> pri[i][1];
        pri[i][2] = i;
        ajuda.insert(pri[i][0]);
        ajuda.insert(pri[i][1]);
    }
    map<int, int> mp;
    int at = 1;
    for(auto i: ajuda) mp[i] = at++;
    sort(pri.begin(), pri.end(), customSort);
    vector<int> resp1(n), resp2(n);
    bit tree;
    tree.init();
    for (int i = 0; i < n; i++){
        if(tree.querry(1000000) - tree.querry(mp[pri[i][1]]-1)) resp1[pri[i][2]] = 1;
        tree.update(mp[pri[i][1]]);
    }
 
    bit tree1;
    tree1.init();
    for (int i = n-1; i >= 0; i--){
        if(tree1.querry(mp[pri[i][1]])) resp2[pri[i][2]] = 1;
        tree1.update(mp[pri[i][1]]);
    }
 
    for(auto i: resp2) cout << i << " ";
    cout << "\n";
    for(auto i: resp1) cout << i << " ";
    cout << "\n";
}