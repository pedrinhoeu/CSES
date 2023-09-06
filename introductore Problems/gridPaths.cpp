#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n = 7, ct = 0;
vector<vector<bool>> visi(7, vector<bool>(7));



void search(ll id, ll jd, ll sum){
    if(id == n or jd == n or id < 0 or jd < 0){
        return;
    }
    if(id == 6 && jd == 6){
        if(sum != 48) return;
        ct++;
        return;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i == 6 || visi[i+1][j]){
                if(j - 1 > 0 && !visi[i][j-1] && j+1 < n && !visi[i][j+1]) return;
            }
            if(i == 0 || visi[i-1][j]){
                if(i - 1 > 0 && !visi[i-1][j] && i+1 < n && !visi[i+1][j]) return;
            }
            if(i == 6 || visi[i+1][j]){
                if(i - 1 > 0 && !visi[i-1][j] && i+1 < n && !visi[i+1][j]) return;
            }
            if(i == 6 || visi[i+1][j]){
                if(i - 1 > 0 && !visi[i-1][j] && i+1 < n && !visi[i+1][j]) return;
            }
        }
           
    }
    

}

int main(){

}