#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    if(n == 1){
        cout << 1 << "\n";
    }
    else if(n <= 3){
        cout << "NO SOLUTION" << "\n";
    }
    else if(n == 4){
        cout << 3 << " " << 1 << " " << 4 << " " << 2 << "\n";
    }
    else{
        if(n % 2 == 0){
            long long e = 1, dir = ((n+1)/2)+1;
            while (dir <= n or e <= (n+1)/2){
                if(dir <= n){
                    cout << dir << " ";
                    dir += 1;
                }
                if(e <= (n+1)/2){
                    cout << e << " ";
                    e += 1;
                }
            }
        }
        else{
            long long e = 1, dir = (n+1)/2;
            while (dir <= n){
                if(dir <= n){
                    cout << dir << " ";
                    dir += 1;
                }
                if(e < (n+1)/2){
                    cout << e << " ";
                    e += 1;
                }
            }
        }
        
    }
    
}