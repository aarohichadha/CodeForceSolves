#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// https://codeforces.com/problemset/problem/1913/B
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        
        string s;
        cin >> s;
        int n = s.size();
        int cnt0 = 0, cnt1 = 0, len_of_t = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                cnt0++;
            } else {
                cnt1++;
            }
        }
        for(char c : s) {
            if(c == '0' && cnt1 > 0) {
                len_of_t++;
                cnt1--;
            }else if(c == '1' && cnt0 > 0) {
                len_of_t++;
                cnt0--;
            } else {
                break;
            }
        }
        cout << n - len_of_t << '\n';
    }

    return 0;
}
