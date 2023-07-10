#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> macas(n);
    for (int i = 0; i < n; ++i) {
        cin >> macas[i];
    }
    
    int minresp = 0;
    int resp1 = 0;
    int resp2 = 0;
    
    for (int i = 0; i <= pow(2, n)/2; i++) {
        string z = bitset<32>(i).to_string();
        z = z.substr(32 - n);
        
        int tim1 = 0;
        int tim2 = 0;
        int j = 0;
        
        while (j < z.length()) {
            if (z[j] == '0') {
                tim1 += macas[j];
            } else {
                tim2 += macas[j];
            }
            j++;
        }
        
        if (abs(tim1 - tim2) < abs(resp1 - resp2) || resp1 == 0 || resp2 == 0) {
            resp1 = tim1;
            resp2 = tim2;
        }
    }
    
    cout << abs(resp1 - resp2) << "\n";
    
    return 0;
}
