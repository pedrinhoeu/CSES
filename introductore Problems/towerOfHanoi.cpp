#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll som=0;

vector<pair<ll, ll>> resp;

void build(ll n, ll ori, ll fim, ll fal){
    if(n == 0) return;
    som ++;
    build(n-1, ori, fal, fim);
    resp.push_back({ori, fal});
    build(n-1, fim, ori, fal);
} 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    build(n, 1, 2, 3);
    cout << som << "\n";
    for(auto i : resp){
        cout << i.first << " " << i.second << "\n";
    }
}