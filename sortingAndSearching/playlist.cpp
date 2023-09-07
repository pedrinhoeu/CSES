#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i].first;
        nums[i].second = i;
    }
    ll comp = 0, ant = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++){
        if(nums[i].first != ant){
            comp++;
        }
        ant = nums[i].first;
        nums[i].first = nums[i].second;
        nums[i].second = comp;
    }
    sort(nums.begin(), nums.end());
    vector<ll> temp(comp+1, -1);
    ll esq=0, dir = 0, resp = 0;
    while(dir < n){
        //cout << resp << " " << nums[dir].second << " " << temp[nums[dir].second] << " " << esq << " " << dir << "\n";
        if(temp[nums[dir].second] >= esq){
            esq = temp[nums[dir].second] + 1;
        }
        else{
            temp[nums[dir].second] = -1;
        }
        temp[nums[dir].second] = dir;
        resp = max(resp, dir-esq+1);
        //cout << resp << " " << nums[dir].second << " " << temp[nums[dir].second] << " " << esq << " " << dir << "\n\n";
        dir++;
        
    }
    cout << resp << "\n";
}