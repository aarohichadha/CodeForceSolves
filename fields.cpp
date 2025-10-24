#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int no_of_fields;
        cin >> no_of_fields;

        long long sum_even = 0;
        vector<long long> odd;

        while(no_of_fields--){
            long long x;
            cin >> x;
            if ((x & 1LL) == 0) sum_even += x;   // even
            else odd.push_back(x);               // odd
        }

        if (odd.empty()) {
            // mower never turns ON -> cannot cut any field
            cout << 0 << '\n';
            continue;
        }

        // We can cut ceil(#odd/2) odd fields; pick the largest ones
        int k = (int(odd.size()) + 1) / 2;
        if (k < (int)odd.size()) {
            nth_element(odd.begin(), odd.begin() + k, odd.end(), greater<long long>());
        }

        //long long ans = sum_even;           // all evens get cut once mower is ON
        for (int i = 0; i < k; ++i) sum_even += odd[i];  // add top-k odd fields

        cout << sum_even << endl;
    }
    return 0;
}
