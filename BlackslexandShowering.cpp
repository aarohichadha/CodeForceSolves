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
        if(n <= 1) {
            cout << 0 << '\n';
            continue;
        }
        vector<long long> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        // as a hacker, i can skip one shower. i will skip the shower with maximum water usage. cost of every shower is the difference between current and previous shower
        
        long long maxDiff = 0, idx = -1;
        for(int i = 1; i <= n-2; i++) {
            long long diff = llabs(a[i] - a[i-1]) + llabs(a[i+1] - a[i]) - llabs(a[i+1] - a[i-1]);
            if(diff > maxDiff) {
                maxDiff = diff;
                // idx = i;
            }
        }
        if(maxDiff < llabs(a[1] - a[0])) {
            maxDiff = llabs(a[1] - a[0]);
            // idx = 0;
        }
        if(maxDiff < llabs(a[n-1] - a[n-2])) {
            maxDiff = llabs(a[n-1] - a[n-2]);
            // idx = n-1;
        }
        long long total_cost = 0;
        for(int i = 1; i < n; i++) {
            total_cost += llabs(a[i] - a[i-1]);
        }
        // if(idx == 0) {
        //     total_cost -= llabs(a[1] - a[0]);
        // } else if(idx == n-1) {
        //     total_cost -= llabs(a[n-1] - a[n-2]);
        // } else {
        //     total_cost -= (llabs(a[idx] - a[idx-1]) + llabs(a[idx+1] - a[idx]) - llabs(a[idx+1] - a[idx-1]));
        // }
        cout << total_cost - maxDiff << '\n';
    }
    return 0;
}