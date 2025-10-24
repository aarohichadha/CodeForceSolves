#include <bits/stdc++.h>
using namespace std;

int main() {
 
    
    int t; 
    if(!(cin >> t)) return 0;
    while (t--) {
        long long n, m;
        long long x, y;
        cin >> n >> m >> x >> y;

        // no effect on ans.
        for (long long i = 0, var; i < n; i++) cin >> var;
        for (long long j = 0, var; j < m; j++) cin >> var;

        cout << (n + m) << endl;
    }
    return 0;
}
