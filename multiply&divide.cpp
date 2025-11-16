#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Your code here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 1){
            cout << 0 << endl;
            continue;
        };
        long long a = 0, b = 0;
        while(n % 2 == 0){
            n /= 2;
            a++;
        }
        while(n % 3 == 0){
            n /= 3;
            b++;
        }

        if(a > b || n != 1) cout << -1 << endl;
        else{
            if(n != 1) cout << -1 << endl;
            else cout << 2*(b - a) + a << endl;
        }
    }
    return 0;
}