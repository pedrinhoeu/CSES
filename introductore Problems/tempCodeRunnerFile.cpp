#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> mat(8);
ll n = 8, cot = 0;
vector<bool> col(8), dig1(16), dig2(16);

void search(ll y){
    if(y == n){
        cot++;
        return;
    }
    for (int i = 0; i < n; i++){
        if(col[i] || dig1[i+y] || dig2[i-y+n-1] || mat[y][i] == '*') continue;
        col[i] = dig1[i+y] = dig2[i-y+n-1] = true;
        search(y+1);
        col[i] = dig1[i+y] = dig2[i-y+n-1] = false;
    }
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 8; i++){
        cin >> mat[i];
    }
    search(0);
    cout << cot << "\n";
}