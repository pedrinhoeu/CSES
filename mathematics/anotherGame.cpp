#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solvetask(){
    ll n;
    cin >> n;    
    bool resp = false;
    ll a;
    for(int i=0; i< n; i++){
        cin >> a;
        if(a&1) resp = true;
    }
    if(!resp) cout << "second\n";
    else cout << "first\n";
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while(t--) solvetask();
}