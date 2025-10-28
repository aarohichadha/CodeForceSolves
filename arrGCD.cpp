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
        int n;
        cin >> n;
        vector<ll> arr(n);
        vector<ll> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
        ll ans = -1;
        ll res;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            if(i == 0){
                res = arr[i];
            }
            else {
                res = __gcd(res, arr[i]);
            }
        }
        if(res == 1){
            cout << 2 << endl;
            continue;
        }
        if(res > 0){
            for(ll p : prime){
                if(res % p != 0){
                    ans = p;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}