#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<string> nums;
    nums.push_back("0");
    nums.push_back("1");
    int i, j;
    for (i = 2; i < (1<<n); i = i<<1){
        for (j = i-1 ; j >= 0 ; j--)
            nums.push_back(nums[j]);
 
        for (j = 0 ; j < i ; j++)
            nums[j] = "0" + nums[j];
 
        for (j = i ; j < 2*i ; j++)
            nums[j] = "1" + nums[j];
    }
 
    for (i = 0 ; i < nums.size() ; i++){
        cout << nums[i] << "\n";
    }
        
}