#include <bits/stdc++.h>
using namespace std;
int main() {
int x,y,l,r;
cin>>x>>y>>l>>r;
for (int i =1; i<l; i++){
    y = y>>1;
} 
for (int i=l;i<=r;i++){
    int b = y&1;
    if(b==1){
        int a = pow(2,i-1);
        x = x|a;
    }
    y = y>>1;
}
cout<<x;
return 0;
}