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
        long long sum = 0;
        int pos = 0;
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            sum += x;
            if(x!=0) {
                pos++;
            }
            // if(x > maxi) {
            //     maxi = x;
            // }
        }
        if(pos == 0) {
            cout << 0 << '\n';
            continue;
        }
        ll maxi = sum - (n-1);
        ll final_ans = min<ll>(pos, maxi);
        cout << final_ans << '\n';
        // if(sum % maxi != 0) {
        //     cout << (sum / maxi) + 1 << '\n';
        //     continue;
        // }
        // cout << sum/maxi << '\n';
    }
    return 0;
}
