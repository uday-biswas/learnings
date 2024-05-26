#include <bits/stdc++.h>
using namespace std;
int main() {
int n=16 , ans =0, i =0;
while(n!=0){
   int last_digit = n & 1 ;     //getting the last digit
   if(last_digit == 0) ans = last_digit * pow(10, i) + ans;  //if the last digit is 0 then it is even
   else ans = last_digit * pow(10, i) + ans;        // if the last digit is 1 then its odd
   i++;
   n = n >> 1;                           //dividing it by 2
}
cout<<ans;
return 0;
}