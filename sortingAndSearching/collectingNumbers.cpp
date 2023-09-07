#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, a, resp = 0;
    cin >> n;
    vector<ll> nums(n+1, 0);
    for (int i = 0; i < n; i++){
        cin >> a;
        if(nums[a-1] == 0){
            resp++;
        }
        nums[a] = 1;
    }
    cout << resp << "\n";
}