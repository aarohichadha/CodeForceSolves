#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; 
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int total2 = 0;
        for (int v : a) if (v == 2) ++total2;

        if (total2 % 2) { 
            cout << -1 << '\n';
            continue;
        }

        int need = total2 / 2;
        int pref2 = 0;
        int ans = -1;
        for (int i = 0; i < n - 1; ++i) {    
            if (a[i] == 2) ++pref2;
            if (pref2 == need) { 
                ans = i + 1;                  
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
