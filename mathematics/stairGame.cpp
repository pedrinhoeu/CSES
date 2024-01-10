#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solvetask(){
        ll n;
        cin >> n;
    
        ll t1 = 0, a;
        for(int i=0; i< n; i++){
              cin >> a;
              if(i&1) t1 ^= a;
        }
        if(t1 == 0) cout << "second\n";
        else cout << "first\n";
    
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while(t--) solvetask();
}