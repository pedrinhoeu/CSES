#include <bits/stdc++.h>
using namespace std;

int main(){
    string pala, imp="";
    int imps=0;
    cin >> pala;
    map<char, int> dic;
    for (char a: pala){
        dic[a] += 1;
        if(dic[a] & 1){
            imps += 1;
        }
        else{
            imps -= 1;
        }
    }
    if(imps > 1){
        cout << "NO SOLUTION" << endl;
    }
    else{
        for (auto i = dic.begin(); i != dic.end(); i++){
            if(i -> second & 1){
                imp = i -> first;
            }
            for (int j = 0; j < (i->second)/2; j++){
                cout << i -> first;
            }
        }
        cout << imp;
        for (auto i = dic.rbegin(); i != dic.rend(); i++){
            for (int j = 0; j < (i->second)/2; j++){
                cout << i -> first;
            }
        }
    }
}