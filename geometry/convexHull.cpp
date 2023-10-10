#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

struct pt{
    ll x, y;
};

ll orientation(pt a, pt b, pt c){
    ll v = a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
    if(v > 0) return 1;
    if(v < 0) return -1;
    return 0;
}
bool collinear(pt a, pt b, pt c) {return orientation(a, b, c) == 0;}
bool cw(pt a, pt b, pt c, bool colinear){
    ll o = orientation(a, b, c);
    return o < 0 || (colinear && o == 0);
}
void convex(vector<pt> &a, bool colinear = true){
    pt p0 = *min_element(a.begin(), a.end(),[](pt a, pt b){
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(),[p0](const pt &a, const pt &b){
        ll o = orientation(p0, a , b);
        if(o == 0){
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y) < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        }
        return o < 0;
    });
    if(colinear){
        int i = a.size()-1;
        while(i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }
    vector<pt> temp;
    for (int i = 0; i < a.size(); i++){
        while(temp.size() > 1 && !cw(temp[temp.size()-2], temp.back(), a[i], colinear)) temp.pop_back();
        temp.push_back(a[i]);
    }
    a = temp;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<pt> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
    }
    convex(a);
    cout << a.size() << "\n";
    for (auto i: a)cout << i.x << " " << i.y << "\n";
    
}