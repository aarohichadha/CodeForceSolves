#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Your code here
    int t;
    cin >> t;
    while(t--){
        int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> temp = a;
    sort(temp.begin(), temp.end());
    if(temp == a || k>1){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    
    }
    return 0;
}