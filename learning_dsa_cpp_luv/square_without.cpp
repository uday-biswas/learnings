#include <bits/stdc++.h>
using namespace std;

//       1 0 1
//     x 1 0 1
//  ------------
//       1 0 1
//     0 0 0 0
//   1 0 1 0 0
// -------------
//   1 1 0 0 1
// -------------
int main() {
    int n,sum=0,k=0,v;
    cin>>n;
    v=n;int x=n;
while(v!=0){             //counting number of bits
    k++;
    v = v>>1;
}
while(k--){            //looping through each bit and if bit is 1 then adding updated n to sum
   int b = x&1;
   if(b==1){
     sum += n;
   }
   x=x>>1;
    n = n<<1;         //updating n by left shifting it by 1 
}
cout<<sum;             //sum is the answer
return 0;
}