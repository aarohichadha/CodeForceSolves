#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int last = -1e9;
        int to_protect = 0;
        string s;
        cin >> s;
        if(s[0] == '1'){
            to_protect++;
            last = 0;
        } 
        
        
        // int protected_cnt = 0;
        // if(s[0] == '1'){
        //     protected_cnt = 1;
        // } 
        

        // for(int i = 0; i<k; i++){
        //     if(s[i] == '1') protected_cnt++;
        // }
        for(int i = 1; i<n; i++){
            // if(i-k >= 0){
            //     if(s[i-k] == '1') protected_cnt--;
            // }
            // if(s[i-1] == '1') protected_cnt++;
            if(s[i] == '1'){
                if(i - last >= k){
                    last = i;
                to_protect++;
                }else{
                    last = i;
                }
                
            }
            
        }
        cout << to_protect << "\n";
         
    }
}