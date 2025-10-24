// Basic C++ competitive programming template
// File: getTogether.cpp

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vll = vector<ll>;

const int INF = 1e9;
const ll LINF = (ll)4e18;

template<typename T>
inline bool chmin(T &a, const T &b){ if(b < a){ a = b; return true; } return false; }
template<typename T>
inline bool chmax(T &a, const T &b){ if(b > a){ a = b; return true; } return false; }

#ifdef LOCAL
#define dbg(...) do{ fprintf(stderr, __VA_ARGS__); } while(0)
#else
#define dbg(...) do{} while(0)
#endif

ll modpow(ll a, ll e, ll mod){
    ll r = 1;
    a %= mod;
    while(e){
        if(e & 1) r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return r;
}

void solve(int tc){
    // Example: read input and solve one test case
    // Replace with problem-specific logic
    int n;
    if(!(cin >> n)) return;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    // sample: output sum
    long long sum = 0;
    for(int x : a) sum += x;
    cout << sum << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // If the problem has multiple test cases, input usually starts with T.
    // Uncomment the next line to read T from input:
    if(!(cin >> T)){
        return 0;
    }
    for(int tc = 1; tc <= T; ++tc){
        solve(tc);
    }
    return 0;
}