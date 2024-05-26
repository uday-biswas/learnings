#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long power(int N,int R)
    {
       //Your code here
       long long ans = 1LL;
       for(int i=0; i<R; i++){
        //    ans = (long long)((((int)ans)%mod * N)%mod); 
        ans = ans * N ;
        if(ans > 1000000007LL)
           ans = ans - 1000000007LL * (int)(ans/1000000007);
       }
       return ans;
    }
int main() {
cout<<power(12,21);
return 0;
}