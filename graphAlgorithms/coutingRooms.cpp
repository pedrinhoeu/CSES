#include <bits/stdc++.h>
using namespace std;

int n, m;

void op(vector<string> &mat, int i, int j){
    if(i < 0 || j < 0 || i == n || j == m || mat[i][j] != '.') return;
    mat[i][j] = '#';
    op(mat, i-1, j);
    op(mat, i+1, j);
    op(mat, i, j-1);
    op(mat, i, j+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; i++){
        cin >> mat[i];
    }
    int resp = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(mat[i][j] == '.'){
                resp++;
                op(mat, i, j);
            }
        }
    }
    cout << resp << "\n";
    
}