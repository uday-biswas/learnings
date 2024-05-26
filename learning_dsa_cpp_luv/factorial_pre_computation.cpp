#include <bits/stdc++.h>
using namespace std;
// 1 < testcases(t) < 10^5
// 1 <= n <= 10^5
int N = 1e5;
int main() {
int fact[N];
fact[0] =1; fact[1] = 1;
for (int i=2; i<=N; i++){
    fact[i] = fact[i-1] * i;
}
int t;
cin>>t;
while(t--){
    int n;
  cin>>n;
  cout<<fact[n]<<endl;
}
return 0;
}