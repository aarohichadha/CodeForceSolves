#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

// Count how many numbers in the n x n multiplication table are <= x
static inline int64 count_le(int64 x, int n) {
    int64 cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += min<int64>(n, x / i);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    // We want the element at 0-indexed position n*n/2 -> 1-indexed k = n*n/2 + 1
    const int64 total = 1LL * n * n;
    const int64 k = total / 2 + 1;

    int64 lo = 1, hi = total, ans = hi;
    while (lo <= hi) {
        int64 mid = (lo + hi) >> 1;
        if (count_le(mid, n) >= k) {
            ans = mid;          // mid is big enough; try smaller
            hi = mid - 1;
        } else {
            lo = mid + 1;       // need larger values
        }
    }

    cout << ans << '\n';
    return 0;
}
