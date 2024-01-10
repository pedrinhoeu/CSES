#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<array<ll, 3>> cust(n);
    for (int i = 0; i < n; i++){
        cin >> cust[i][0] >> cust[i][1];
        cust[i][2] = i;
    }
    sort(cust.begin(), cust.end());
    vector<ll> resp(n);
    ll quant = 1;
    priority_queue<array<ll, 2>> pq;
    pq.push({0, 1});
    
    for (int i = 0; i < n; i++){
        auto temp = pq.top();
        if(-temp[0] >= cust[i][0]){
            quant++;
            resp[cust[i][2]] = quant;
            pq.push({-cust[i][1], quant});
        }
        else{
            pq.pop();
            resp[cust[i][2]] = temp[1];
            pq.push({-cust[i][1], temp[1]});
        }
    }
    cout << quant << "\n";
    for(auto i: resp) cout << i << " ";
    cout << "\n";   
}