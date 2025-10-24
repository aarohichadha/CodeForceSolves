// given an array, split it into 3 parts st. array 
// The product of all numbers in the first set is less than zero ( < 0).
// The product of all numbers in the second set is greater than zero ( > 0).
// The product of all numbers in the third set is equal to zero.
// Each number from the initial array must occur in exactly one set.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a1 = 1, a2 = 1, a3 = 1;
    vector<int> arr;
    vector<int> arr1;
    vector<int> arr2;
    vector<int> arr3;
    int k = 0;
    while(n--){
        int ele;
        cin>>ele;
        if(ele<0) k++;
        arr.push_back(ele);
    }
    sort(arr.begin(), arr.end());
    if(arr[n-1] == 0){
        
    }
    if(k == 1){
        arr1.push_back(arr[1]);
    }else if(k%2 == 1){

    }

    
}