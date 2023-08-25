#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> macas(n);
    for (int i = 0; i < n; ++i) {
        cin >> macas[i];
    }
    ll minresp = 1e18;

    for (int i = 0; i < 1<<n; i++) {
        ll temp1 = 0, temp2 = 0;
        
        for (int j = 0; j < n; j++){
            if((1<<j) & i){
                temp1 += macas[j];
            }
            else{
                temp2 += macas[j];
            }
        }
        minresp = min(minresp, abs(temp1 - temp2));
    }
    cout << minresp << "\n";    
    return 0;
}