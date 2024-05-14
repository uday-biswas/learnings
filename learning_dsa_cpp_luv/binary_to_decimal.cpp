#include <bits/stdc++.h>
using namespace std;
int main() {
    int n=10100 ,ans=0,i=0; 
    while(n!=0){ 
      int last_digit = n %10;         //taking the last digit 
      ans = ans + pow(2,i) * last_digit;   //multiplying the last digit with appropriate power of 2 and adding to the result
      i++;                               //increasing the power for the next digit
      n = n/10;                           
    }
    cout<<ans;
return 0;
}