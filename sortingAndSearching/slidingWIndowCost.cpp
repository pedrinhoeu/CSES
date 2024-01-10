#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll esq=0, dir=0;
void equal(multiset<ll> &men, multiset<ll> &mai){
    while (men.size() > 1 + mai.size()) {
        auto temp = --men.end();
        dir += *temp;
        esq -= *temp;
        mai.insert(*temp);
        men.erase(temp);
    }
    while (mai.size() > men.size()) {
        
        auto temp = mai.begin();
        dir -= *temp;
        esq += *temp;
        men.insert(*temp);
        mai.erase(temp);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    if(k == 1){
        for (int i = 0; i < n; i++) cout << 0 << " ";
        cout << "\n";
        return 0;
    }
    else if(k == 2){
        for (int i = 1; i < n; i++) cout << abs(nums[i] - nums[i-1]) << " ";
        cout << "\n";
        return 0;
    }
    multiset<ll> men, mai;
    for (int i = 0; i < k; i++){
        men.insert(nums[i]);
        esq += nums[i];
    } 
    equal(men, mai);
    cout << dir - (*(--men.end()))*((k)/2) + (*(--men.end()))*((k+1)/2) - esq << " ";
    
    for (int i = k; i < n; i++){
        
        if(nums[i-k] <= *(--men.end())){
            auto temp = men.lower_bound(nums[i-k]);
            esq -= *temp;
            men.erase(temp);
            
        }
        else{
            auto temp = mai.lower_bound(nums[i-k]);
            dir -= *temp;
            mai.erase(temp);
        }
        
        if(nums[i] <= *(--men.end())){
            men.insert(nums[i]);
            esq += nums[i];
        } 
        else{
            mai.insert(nums[i]);
            dir += nums[i];
        } 
        
        equal(men, mai);
        cout << dir - (*(--men.end()))*((k)/2) + (*(--men.end()))*((k+1)/2) - esq << " ";
    }
    cout << "\n";
}