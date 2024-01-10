#include <bits/stdc++.h>
using namespace std;
int main() {
int t;
cin>>t;
while(t--){
    int fact =1,n;
    cin>>n;
    for(int i=2; i<=n; i++){
        fact = fact * i;
    }
    cout<<fact<<endl;
}
return 0;
}