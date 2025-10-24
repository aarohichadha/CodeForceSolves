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
        cin>>n;
        vector<int> p;
        vector<int> q(n, 0);
        for(int i = 0; i<n; i++){
            int x; cin>>x;
            p.push_back(x);
            q[x-1] = i;
        }
        long long s = q[n-1], e = q[n-1];
        bool result = true;
        for(int i = n-2; i >= 0; i--){
            s = min((int)s, q[i]), e = max((int)e, q[i]);
            if(e - s != n - 1 - i){
                result = false;
                break;
            }
            // we calculate the lenght of current segment

    }
        if(result) cout<<"YES" << endl;
        else cout<<"NO" << endl;
    }
    return 0;
}