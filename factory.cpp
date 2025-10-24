#include <bits/stdc++.h>
using namespace std;

bool isPossible(const vector<long long>& arr, long long time, long long need) {
    long long made = 0;
    for (long long k : arr) {
        made += time / k;
        if (made >= need) return true;  // early stop
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long t;
    if (!(cin >> n >> t)) return 0;
    if (t == 0) { cout << 0 << '\n'; return 0; }

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long lo = 0;
    long long hi = *min_element(a.begin(), a.end()) * t; // fastest machine alone

    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (isPossible(a, mid, t)) hi = mid;   // can make t → try smaller time
        else lo = mid + 1;                     // can't → need more time
    }
    cout << lo << '\n';
    return 0;
}
