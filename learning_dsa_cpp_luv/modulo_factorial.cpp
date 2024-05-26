#include <bits/stdc++.h>
using namespace std;
void modulo_factorial(int n,int mod){
    int fact = 1;
    for (int i=2; i<=n; i++){
        fact = (fact * i) % mod;
    }
    cout<<fact;
}
int main() {
int n,mod;
cin>>n>>mod;
modulo_factorial(n,mod);
return 0;
}