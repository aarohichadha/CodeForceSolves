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
    vector<ll> land;
    for(int i = 0; i < n; ++i){
        ll x;
        cin >> x;
        land.push_back(abs(x));
    }
    sort(land.begin(), land.end());
    
    ll ans = 0;
   
    for(int i = 0; i<n; i++){
        auto itr = upper_bound(land.begin(), land.end(), land[i]*2);
        itr--;
        ans += itr - land.begin() - i;
    }
    cout << ans << '\n';
    return 0;
}