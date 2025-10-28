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
        vector<int> arr(n);
        vector<int> cost(n);
        bool sorted = true;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            if(i > 0 && arr[i] < arr[i-1]) sorted = false;
        }
        
        ll total_cost = 0;
        for(int i = 0; i<n; i++){
            cin >> cost[i];
            total_cost += cost[i];
        }
        if(sorted || n <= 1){
            cout << 0 << endl;
            continue;
        }
        
        vector<int> dp(n, 0);
        // int max_cst = *max_element(cost.begin(), cost.end());

        // for(int i = 0; i<n; i++){

        // }
        ll res = 0;
        for(int i = 0; i<n; i++){
            dp[i] = cost[i];
            for(int j = 0; j<i; j++){
                if(arr[i] >= arr[j]){
                    dp[i] = max(dp[i], dp[j] + cost[i]);
                }
            }
            res = max(res, (ll)dp[i]);
        }
            
        
        cout << total_cost - res << endl;
    }
    return 0;
}