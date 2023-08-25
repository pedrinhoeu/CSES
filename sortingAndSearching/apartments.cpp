#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m, d;
    cin >> n >> m >> d;
    ll resp = 0;
    vector<ll> apts(n), mora(m);
    for (int i = 0; i < n; i++){
        cin >> apts[i];
    }
    for (int i = 0; i < m; i++){
        cin >> mora[i];
    }
    sort(apts.begin(), apts.end());
    sort(mora.begin(), mora.end());
    
    ll id = 0;
    for (int i = 0; i < n;){
        if(id == m) break;
        if(apts[i]-d <= mora[id] && apts[i]+d >= mora[id]){
            id++;
            resp++;
            i++;
        }
        else if(apts[i]-d > mora[id]){
            id++;
        }
        else{
            i++;
        }
    }
    cout << resp << "\n";
}