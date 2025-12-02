#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // Step 1: remove all 1's
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) a[i]++;     // 1 -> 2
        }

        // Step 2: enforce a[i+1] % a[i] != 0 by modifying the right element
        for (int i = 0; i + 1 < n; i++) {
            if (a[i + 1] % a[i] == 0) {
                a[i + 1]++;            // one increment is enough
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
