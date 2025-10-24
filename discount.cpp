#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> prices;
        vector<int> discounts;
        long long totalCost = 0;
        for(int i = 0; i < n; i++){
            int price;
            cin >> price;
            totalCost += price;
            prices.push_back(price);
        }
        for(int i = 0; i < k; i++){
            int discount;
            cin >> discount;
            discounts.push_back(discount);
        }
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end());
        int i = 0;
        // while(i<k && discounts[i] == 1){
        //     int x = *max_element(prices.begin(), prices.end());
        //     totalCost -= x;
        //     prices.erase(remove(prices.begin(), prices.end(), x), prices.end());
        //     i++;
        // }
        // while(i<k){
        //     int a = 0, b = []
        // }
        for(int j = 0; j<k; j++){
            if(i + discounts[j] - 1 < prices.size()){
                totalCost -= prices[i + discounts[j] - 1];
                i += discounts[j];
            }else break;
        }
        cout << totalCost << endl;
    }
    

    return 0;
}