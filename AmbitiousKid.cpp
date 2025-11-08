#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    long long res = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        if (x == 0) {
            cout << 0 << '\n';
            return 0;
        }
        long long ax = x < 0 ? -x : x;
        if (ax < res) res = ax;
        // if (res == 0) { // can't get smaller than 0
        //     cout << 0 << '\n';
        //     return 0;
        // }
    }

    cout << res << '\n';
    return 0;
}