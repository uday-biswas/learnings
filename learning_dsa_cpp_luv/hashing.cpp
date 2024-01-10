/*given array a of N integers. given Q queries and in each query given a 
number X , print count of that number in array .
constrainsts 
1 <= N <= 10^5 
1 <= a[i] <= 10^7
1 <= Q <= 10^5
*/
#include <bits/stdc++.h>
using namespace std;
const int m = 1e7 +7; 
int hsh[m];            //global arrays are always initialized with zero elements

int main() {
int n,q; 
cin>>n;
int a[n];
for(int i=0; i<n; i++){
    cin>> a[i];
    hsh[a[i]]++;           //updating the hashing array
}
cin>>q;
while(q--){
    int x,f=0;
    cin>>x;
    cout<<hsh[x]<<endl;
}
return 0;
}
