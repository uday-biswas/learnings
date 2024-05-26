#include <bits/stdc++.h>
using namespace std;
int main() {
int t,n,f;
cin>>t;
while(t--){
    cin>>n;
    int mul =1;
    for (int i=0; i<n; i++){
        cin>>f;
        mul = mul * f;
    }
    int d = mul % 10 ;
    if (d == 2 || d == 3|| d == 5){
        cout<<"yes";
    }
    else cout<<"no";
}
return 0;
}