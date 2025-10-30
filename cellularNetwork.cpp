#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static bool isPossible(ll mid, const vector<int>& city, const vector<int>& tower) {
    int n = (int)city.size();
    int m = (int)tower.size();
    int j = 0; // pointer on towers

    for (int i = 0; i < n; ++i) {
        // move j to the first tower that could possibly cover city[i]
        // i.e., tower[j] >= city[i] - mid
        while (j < m && (ll)tower[j] < (ll)city[i] - mid) j++;

        // now tower[j] is the first tower >= city[i]-mid (if j<m)
        // it covers city[i] iff tower[j] <= city[i] + mid
        if (j == m || (ll)tower[j] > (ll)city[i] + mid) return false;
        // do NOT advance j here; the same tower can cover later cities too
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> city(n), tower(m);
    for (int i = 0; i < n; ++i) cin >> city[i];
    for (int i = 0; i < m; ++i) cin >> tower[i];

    if (m == 0) { // no towers -> impossible
        cout << -1 << '\n';
        return 0;
    }

    sort(city.begin(), city.end());
    sort(tower.begin(), tower.end());

    ll lo = 0, hi = 1e12; // generous upper bound
    ll ans = -1;

    // Optional tighter hi: max over cities of min distance to nearest tower
    // (kept simple with big hi; binary search will shrink it)

    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (isPossible(mid, city, tower)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
