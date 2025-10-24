#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int x;
        cin >> x;
        unordered_set<int> freq;
        bool ok = 0;                

        while (x--) {
            int gear;
            cin >> gear;
            if (freq.count(gear)) ok = 1;  
            else freq.insert(gear);
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
     
    return 0;
}
