#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, q, a;
    cin >> q >> n;
    set<ll> farls;
    multiset<ll> esp;
    esp.insert(q);
    farls.insert(0);
    farls.insert(q);
    for (int i = 0; i < n; i++){
        cin >> a;
        farls.insert(a);
        auto mai = farls.upper_bound(a), men = --farls.lower_bound(a), apag = esp.lower_bound((*mai) - (*men));
        esp.erase(apag);
        
        esp.insert((*mai) - a);
        esp.insert(a - (*men));
        
        cout << *(--esp.end()) << " ";
    }
    cout << "\n";
    
}