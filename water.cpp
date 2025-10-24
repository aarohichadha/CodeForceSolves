#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; string s; 
        cin >> n >> s;
        int ans = 0;
        bool flag = false;
        for(int i = 0; i<n; i++){
            if(s[i] == '.' && i+1<n && s[i+1] == '.' && i+2<n && s[i+2] == '.'){
                flag = true;
                break;
                
            }else if(s[i] == '.'){
                ans++;
            }
        }
        if(flag) cout << 2 << "\n";
        else cout << ans << "\n";
    }
    return 0;
}
