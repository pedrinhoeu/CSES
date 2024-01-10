#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pt{
    ll x, y;
};

ll orientation(pt a, pt b, pt c){
    ll o = a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
    if(o == 0) return 0;
    else if(o > 0) return 1;
    else return -1;
}

void solvetask(){
    pt p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
    if(((orientation(p1, p2, p3) != orientation(p1, p2, p4)) || ((orientation(p1, p2, p3) == orientation(p1, p2, p4)) && orientation(p1, p2, p3) == 0))          &&  ((orientation(p3, p4, p1) != orientation(p3, p4, p2)) || ((orientation(p3, p4, p1) == orientation(p3, p4, p2)) && orientation(p3, p4, p1) == 0))) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t;
    cin >> t;
    while(t--) solvetask();
    return 0;
}