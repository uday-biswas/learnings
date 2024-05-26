#include <bits/stdc++.h>
using namespace std;
int power_2(int n){
    //base condition
    if(n == 1) return 2;

    //no processing required

    //recurrence relation
    return 2 * power_2(n-1);
}
int main() {
int n;
cin>>n;
int ans = power_2(n);
cout<<ans<<endl;
return 0;
}