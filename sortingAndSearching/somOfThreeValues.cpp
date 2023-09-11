#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> nums(n), ori;
    for (int i = 0; i < n; i++){
        cin >> nums[i].first;
        nums[i].second = i+1;
    }
    sort(nums.begin(), nums.end());
    ll a = -1, b = -1, c = -1, l, r, q;
    bool achou = false;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            l = j+1;
            r = n-1;
            q = k - nums[i].first - nums[j].first;
            while(l <= r){
                ll mid = (l+r)/2;
                if(nums[mid].first == q){
                    a = nums[i].second;
                    b = nums[j].second;
                    c = nums[mid].second;
                    achou = true;
                    break;
                }
                else if(nums[mid].first < q){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            if(achou) break;
        }
        if(achou) break;
    }
    if(a == -1){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << a << " " << b << " " << c << "\n";
    }
}