#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n), freq(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            ++freq[arr[i]];
        }

        // If any value's total frequency isn't divisible by k, no subarray works
        bool yes = true;
        for (int v = 1; v <= n; ++v) {
            if (freq[v] % k != 0) { yes = false; break; }
        }
        if (!yes) {
            cout << 0 << endl;
            continue;
        }


        vector<int> cap(n + 1, 0);
        for (int v = 1; v <= n; ++v) cap[v] = freq[v] / k;


        vector<int> countFreq(n + 1, 0);
        long long result = 0;
        int L = 0;
        for (int R = 0; R < n; ++R) {
            int v = arr[R];
            ++countFreq[v];
          
            while (countFreq[v] > cap[v]) {
                --countFreq[arr[L]];
                ++L;
            }
            result += (R - L + 1);
        }

        cout << result << endl;
    }
    return 0;
}
