#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a + (c/2) > b + (c/2)) cout << "First" << '\n';
        else if(a + (c/2) < b + (c/2)) cout << "Second" << '\n';
        else cout << "First" << '\n';
    }
    return 0;
}