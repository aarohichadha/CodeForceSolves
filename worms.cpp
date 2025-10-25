#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;

constexpr int INF = 1e9;
constexpr ll LINF = (ll)4e18;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int sum = 0;
    // prefix sums of moles in each pile
    vector<int> moles(n);
    for (int i = 0; i < n; ++i) {
        cin >> moles[i];
        sum += moles[i];
        moles[i] = sum;
    }

    int m;
    cin >> m;
    vector<int> worms(m);
    for (int i = 0; i < m; ++i) {
        cin >> worms[i];
    }

    // find the pile for each worm using binary search
    for (int i = 0; i < m; ++i) {
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (worms[i] <= moles[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cout << lo + 1 << '\n';
    }
  
    return 0;
}