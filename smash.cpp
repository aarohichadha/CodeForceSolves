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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        set<int> s(all(arr));
        int x = s.size();
        cout << x*2 - 1 << endl;

    

        // Your code here
    }
    return 0;
}