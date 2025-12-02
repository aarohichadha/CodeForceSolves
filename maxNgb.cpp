#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if(n <= 1){
            cout << n << '\n';
            continue;
        }
        if(n == 2){
            cout << 9 << '\n';
            continue;
        }
        if(n == 3){
            cout << 29 << '\n';
            continue;
        }
        if(n == 4){
            cout << 56 << '\n';
            continue;
        }
        long long a = n-2;
        cout << (n*n - 1) + 3*n*a + 3*n - 3 + n*(n-3) + n-1 << '\n';
    }
    return 0;
}
