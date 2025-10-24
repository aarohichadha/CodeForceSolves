#include <bits/stdc++.h>
using namespace std;

// Can we split arr into at most k parts so each part's sum <= mid?
static bool isPossible(long long mid, const vector<long long>& arr, int k) {
    long long sum = 0;
    int pieces = 1;
    for (long long x : arr) {
        if (x > mid) return false;          // single element cannot exceed mid
        if (sum + x <= mid) sum += x;
        else {
            ++pieces;
            if (pieces > k) return false;
            sum = x;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> arr(n);
    long long lo = 0, hi = 0;
    for (int i = 0; i < n; ++i) {
        long long x; 
        cin >> x;
        arr[i] = x;              // assign, don't push_back
        lo = max(lo, x);         // lower bound: max element
        hi += x;                 // upper bound: total sum
    }

    long long ans = hi;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (isPossible(mid, arr, k)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
