/*given an array and left , right index
will be given , to find the sum from left to right*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int a[N],pf[N];
int main() {
int n;
cin>>n;
cin>>a[0];
pf[0] = a[0];
for ( int i=1; i<n; i++){
    cin>>a[i];
    pf[i] = pf[i-1] + a[i];
}
int q;
cin>>q;
while(q--){
    int l,r;
    cin>>l>>r;
    long long sum =0;
    sum = pf[r] - pf[l-1];
    cout<<sum<<endl;
}
return 0;
}