#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fast_io ios::sync_with_stdio(false); cin.tie(0);

int main() {
    fast_io
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt = 0;
        while(n--){
            
            int a, b;
            cin >> a >> b;
            if(a>b) cnt++;
        }
        cout << cnt << "\n";
        // Your code here
    }
    return 0;
}