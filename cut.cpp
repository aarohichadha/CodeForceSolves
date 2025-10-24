#include <iostream>
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
        vector<int> a;
        int midSum = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            midSum += x;
            a.push_back(x);

        }
        int l = 0, r = 0;
        midSum -= (a[0] + a[n-1]);
        int lsum = a[0], rsum = a[n-1];

        int s1 = lsum%3, s2 = rsum%3, s3 = midSum%3;
        int i = 1;
        int j = n - 2;
        bool flag = false;
        while(i <= j){
            if((s1 == s2 && s2 == s3) || (s1 != s2 && s2 != s3 && s1 != s3)){
                l = i;
                r = j+1;
                cout << l << " " << r << endl;
                flag = true;
                break;
            }
            if(lsum < rsum && i <= j){
                lsum += a[i];
                midSum -= a[i];
                i++;
                s1 = (lsum+3)%3;
            }
            else if(rsum <= lsum && i <= j){
                rsum += a[j];
                midSum -= a[j];
                j--;
                s2 = (rsum+3)%3;
            }
            // for(int k = i; k <= j; k++){
            //     s3 = (s3 + a[k])%3;
            // }
            s3 = (midSum+3)%3;
            // if(s1 == s2 && s2 == s3){
            //     l = i;
            //     r = n - 1 - j;
            //     cout << l << " " << r << endl;
            //     flag = true;
            //     break;
            // }else if(s1 != s2 && s2 != s3 && s1 != s3){
            //     l = i;
            //     r = n - 1 - j;
            //     cout << l << " " << r << endl;
            //     flag = true;
            //     break;
            // }

        }
        if(!flag) cout << 0 << " " << 0 << endl;
        
    }
    
    return 0;
}