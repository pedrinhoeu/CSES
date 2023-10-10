#include <bits/stdc++.h>
using namespace std;
 
int n, m, ax, ay;
 
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    vector<string> mat(n);
    vector<vector<char>> volta(n, vector<char>(m, '!'));
    for (int i = 0; i < n; i++) cin >> mat[i]; 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(mat[i][j] == 'A'){
                ax = i;
                ay = j;
                break;
            }
        }
    }
    volta[ax][ay] = '?';
    queue<pair<pair<int, int>, pair<int, char>>> q;
    q.push({{ax, ay}, {0, '!'}});
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        int x = temp.first.first, y = temp.first.second, d = temp.second.first;
        char pal = temp.second.second;
        if(x < 0 || y < 0 || x == n || y == m) continue;
        volta[x][y] = pal;
        if(mat[x][y] == 'B'){
            cout << "YES\n" << d << "\n";
            string temp = "";
            while(x != ax || y != ay){
                temp += volta[x][y];
                if(volta[x][y] == 'U') x++;
                else if(volta[x][y] == 'D') x--;
                else if(volta[x][y] == 'L') y++;
                else if(volta[x][y] == 'R') y--;
            }
            reverse(temp.begin(), temp.end());
            cout << temp << "\n";
            return 0;
        }
        
        if(x-1 >= 0 && (mat[x-1][y] == '.' || mat[x-1][y] == 'B')){
            if(mat[x-1][y] == '.') mat[x-1][y] = '#';
            q.push({{x-1, y}, {d+1, 'U'}});
        } 
        if(x+1 < n && (mat[x+1][y] == '.' || mat[x+1][y] == 'B')){
            if(mat[x+1][y] == '.') mat[x+1][y] = '#';
            q.push({{x+1, y}, {d+1, 'D'}});
        } 
        if(y-1 >= 0 && (mat[x][y-1] == '.' || mat[x][y-1] == 'B')){
            if(mat[x][y-1] == '.') mat[x][y-1] = '#';
            q.push({{x, y-1}, {d+1, 'L'}});
        } 
        if(y+1 < m && (mat[x][y+1] == '.' || mat[x][y+1] == 'B')){
            if(mat[x][y+1] == '.') mat[x][y+1] = '#';
            q.push({{x, y+1}, {d+1, 'R'}});
        } 
        mat[x][y] = '#';
    }
 
    cout << "NO\n";
    return 0;
}
