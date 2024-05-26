#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int a[N];
int main() {
    int n;
    cin>>n;
    for (int i=0; i< n; i++){
        cin>> a[i];
    }
int q;
cin>>q;
while(q--){
    int l,r;
    cin>>l>>r;
    long long sum =0;
    for (int i = l; i<= r; i++){
        sum += a[i];
    }
    cout << sum<< endl;
}
return 0;
}