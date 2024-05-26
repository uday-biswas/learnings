//given 3 positive numbers a, b , c . we make a set which contains
//numbers that are either multiples of a or b or (a and b both)
//in increasing order. we take the c-th number of set and print from 
//c-th number to 0 with a step value of a or b whichever it is multiple
// and if its a multiple of both, then use step value as lcm(a, b).
  //input format : one line containing numbers - a, b, and c
  //output format : one line containing values from c-th number to 0 with the step value.
  //sample input : 3 5 14
  //sample output : 30 15 0
#include <bits/stdc++.h>
using namespace std;
int lcm(int a , int b){
    int lcm;
    for (int i=1; i<=a*b; i++){
         if (i % a ==0 && i% b ==0){
            lcm = i;
            break;
         }
    }
    return lcm;
}
int main() {
int a,b,c,cth;
cin>>a>>b>>c;
int arr[c],k=0,j=c;
for (int i=1; c>0; i++){
   if (i%a==0 || i%b ==0){
    c--;
    arr[k]=i;
    k++;
   }
}
cth = arr[j-1];
int l = lcm(a,b), step;
if(cth % l==0){
    step = l;
}
else if (cth % a ==0){
    step = a;
}
else if (cth % b ==0){
    step = b;
}
while(cth>=0){
        cout<<cth<<" ";
        cth = cth - step;
    }
return 0;
}