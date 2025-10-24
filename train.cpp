#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if(!(cin >> t)) return 0;
    while (t--) {
        int n, k; 
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int res = max(a[0], 2 * (k - a[n - 1]));   // include start gap and doubled end
        for (int i = 0; i + 1 < n; i++) {
            res = max(res, a[i + 1] - a[i]);       // middle gaps
        }
        cout << res << "\n";
    }
    return 0;
}
