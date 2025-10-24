#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin >> x;
        // vector<int> powerOf10 = {}
        string str_of_x = to_string(x);
        int size = str_of_x.length();
        if(str_of_x[0] == '9') size+=1;
        int res = 1;
        for(int i = 0; i<size; i++){
            res*=10;
        }
        cout << res - 1 - x << endl;

    }
    return 0;
}