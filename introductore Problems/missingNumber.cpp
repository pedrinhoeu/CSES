#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> nums(n-1);
    for (int i = 0; i < n-1; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++){
        if(i == n-1){
            cout << i+1 << "\n";
            break;
        }
        if(nums[i] != i+1){
            cout << i+1 << "\n";
            break;
        }
    }
    
}