#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        int sum = 0;
        for(int i = 0; i<n; i++){
            if(i%2 == 0){
                sum+=arr[i];
            }else{
                sum -= arr[i];
            }
        }
    }
    return 0;
}