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
cout << lcm(5,15);
return 0;
}