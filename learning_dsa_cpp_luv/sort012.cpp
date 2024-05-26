#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    cout<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<int> arr;
        for(int i=0; i< n;i++){
            arr.push_back(a[i]);
        }
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
return 0;
}