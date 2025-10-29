#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

constexpr int INF = 1e9;
constexpr ll LINF = (ll)4e18;

bool canPlace(const vector<int>& stalls, int cows, int minDist) {
    int placed = 1;
    int last_pos = stalls[0];
    for (size_t i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - last_pos >= minDist) {
            last_pos = stalls[i];
            if (++placed == cows) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
    int n, c;
    cin >> n >> c;

    vector<int> stalls(n);
    for (int i = 0; i < n; ++i) cin >> stalls[i];
    sort(stalls.begin(), stalls.end());

    ll lo = 1;
    ll hi = stalls.back() - stalls.front();
    ll best = 0;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (canPlace(stalls, c, mid)) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << best << '\n';
    }
    return 0;
    
}