#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct pt{
    ll x, y;
};
 
void orientation(pt a, pt b, pt c){
    ll o = a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
    if(o == 0) cout << "TOUCH\n";
    else if(o > 0) cout << "LEFT\n";
    else cout << "RIGHT\n";
}
 
void solvetask(){
    pt p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    orientation(p1, p2, p3);
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t;
    cin >> t;
    while(t--) solvetask();   
}