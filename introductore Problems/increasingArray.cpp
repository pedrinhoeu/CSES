#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, resp = 0, o = 0, mv = 0;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        resp += max(o, mv - nums[i]);
        if(mv < nums[i]){
            mv = nums[i];
        }
    }
    cout << resp << "\n";
    
}