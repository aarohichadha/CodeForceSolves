#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// https://codeforces.com/problemset/problem/1485/A
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        
        int a , b;
        cin >> a >> b;
        long long ans = INT_MAX;
        for(int i = 0; i < 32; i++) {
            int nb = b + i;
            if(nb == 1) {
                continue;
            }
            long long curr = i;
            int na = a;
            while(na > 0) {
                na /= nb;
                curr++;
            }
            ans = min(ans, curr);
        }        cout << ans << '\n';
    }

    return 0;
}
