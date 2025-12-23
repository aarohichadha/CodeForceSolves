#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long mini = LLONG_MAX;
        vector<long long> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mini = min(mini, a[i]);
        }
        long long ans = LLONG_MAX;
        for(long long x : a){
            if(x != mini){
                ans = min(ans, x - mini);
            }
        }
        cout << max(ans, mini) << '\n';
        
    }
    return 0;
}