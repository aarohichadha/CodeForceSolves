#include <bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    if(!test) return 0;
    while(test--){
        string s; // binary string
        int n; // lenght
        cin >> n >> s;
        int no_of_zero = 0;
        for(char c : s){
            if(c == '0') no_of_zero++;
        }
        int shift = 0;
        for(int i = 0; i<no_of_zero; i++){
            if(s[i] == '1'){
                shift++;
            }
        }
        cout << shift << endl;
    }
    return 0;
}