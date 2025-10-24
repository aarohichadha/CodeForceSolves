#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        long long ans = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            ans *= 2;
        }
        vector<long long> dp(n+1, 0);
        
        



        cout << ans%mod << endl;
        
    }

    // Your code here

    return 0;
}