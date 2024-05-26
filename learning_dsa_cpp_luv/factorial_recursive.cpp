#include <bits/stdc++.h>
using namespace std;
int factorial(int n){
    //base conditon
    if(n == 1) return 1;
    
    //no processing required

    //recurrence relation 
    return n * factorial(n-1);
}
int main() {
int n;
cin>>n;
int ans = factorial(n);
cout<<ans<<endl;
return 0;
}