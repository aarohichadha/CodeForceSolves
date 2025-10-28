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
        bool odd = false, even = false;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] % 2 == 0) even = true;
            else odd = true;
        }
        if(odd && even){
            sort(arr.begin(), arr.end());
            for(int i = 0; i<n; i++) cout << arr[i] << " ";
            cout << "\n";
        } else {
            for(int i = 0; i<n; i++) cout << arr[i] << " ";
            cout << "\n";
        }
        

    }
    return 0;
}