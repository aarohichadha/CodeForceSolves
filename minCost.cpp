#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n+1);
        vector<int> foundELE(n+1); // for ones
        vector<int> c; // for zeros
        for(int i = 0; i<n; i++){
            cin>>a[i];
            if(a[i] == 0) c.push_back(i);
            else foundELE[i] = 1;
        }
        int l = 0, r = n - 1;
        // if(c.size() == 0){
        //     for(int i = 0; i<n; i++){
        //         if(a[i] != i){
        //             l = i; break;
        //         }
        //     }
        //     for(int i = n - 1; i>=0; i--){
        //         if(a[i] != i){
        //             r = i; break;
        //         }
        //     }

        // }
        int z = 0, o = 0;
        for(int i = 0; i<n; i++){
            if(a[i] == 0){
                z++;
            }if(a[i] != i+1){
                o++;
            }

        }
        if
        
        
       
    }
    return 0;
}