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
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a == b && a == c && a == d){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}