#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    vector<pair<int, int>> mons;
    for (int i = 0; i < n; i++) cin >> mat[i];
    int ax, ay;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
        if(mat[i][j] == 'A'){
            ax = i;
            ay = j;
        }
        if(mat[i][j] == 'M') mons.push_back({i, j});
        
    }
    char volt[n][m];
    queue<pair<pair<int, int>, char>> q;
    for(auto i: mons)q.push({i, 'M'});
    q.push({{ax, ay}, 'A'});
    while(!q.empty()){
        int x = q.front().first.first, y = q.front().first.second;
        char op = q.front().second;
        q.pop();
        if((x == 0 or x == n-1 or y == 0 or y == m-1) && (mat[x][y] == 'L' || mat[x][y] == 'R' || mat[x][y] == 'D' || mat[x][y] == 'U' || mat[x][y] == 'A') && op == 'A'){
            //for (auto i: mat) cout << i << "\n";   
            int resp = 0;
            string re = "";
            while(x != ax || y != ay){
                re += mat[x][y];
                if(mat[x][y] == 'L') y+=1;
                else if(mat[x][y] == 'R') y-=1;
                else if(mat[x][y] == 'U') x+=1;
                else if(mat[x][y] == 'D') x-=1;
                resp++;
            }
            reverse(re.begin(), re.end());
            cout << "YES\n" << resp << "\n" << re << "\n";
            return 0;
        }
        if(x-1 >= 0 && mat[x-1][y] == '.'){
            q.push({{x-1, y}, op});
            if(op == 'A') mat[x-1][y] = 'U';
            else mat[x-1][y] = 'M';
        }
        if(x+1 < n && mat[x+1][y] == '.'){
            q.push({{x+1, y}, op});
            if(op == 'A') mat[x+1][y] = 'D';
            else mat[x+1][y] = 'M';
        }
        if(y-1 >= 0 && mat[x][y-1] == '.'){
            q.push({{x, y-1}, op});
            if(op == 'A') mat[x][y-1] = 'L';
            else mat[x][y-1] = 'M';
        }
        if(y+1 < m && mat[x][y+1] == '.'){
            q.push({{x, y+1}, op});
            if(op == 'A') mat[x][y+1] = 'R';
            else mat[x][y+1] = 'M';
        }
    }
    cout << "NO\n";
}