#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    while(n--){
        long long a, b, resp;
        cin >> a >> b;
        if(a > b){
            if(a%2 == 0){
                resp = (a)*(a);
                resp = resp - b + 1;
            }
            else{
                resp = (a-1)*(a-1)+1;
                resp = resp + b - 1;
            }
        }
        else{
            if(b%2 == 0){
                resp = (b-1)*(b-1)+1;
                resp = resp + a - 1;
            }
            else{
                resp = (b)*(b);
                resp = resp - a + 1;
            }
        }
        cout << resp << "\n";
    }
    
}