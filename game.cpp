#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
   while(t--){
    int n;
    cin >> n;
    // agar n%3 == 0 toh vanya wins immediately
    // but if not, then vova usse 10th move tk jeetne nhi dega
    if(n % 3 != 0) cout << "First\n";
    else cout << "Second\n";
    // Your code here
   }
    return 0;
}