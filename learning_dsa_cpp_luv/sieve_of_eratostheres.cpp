#include <bits/stdc++.h>
using namespace std;
int count_no_of_prime(int n){
    int cnt =0;
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for(int i=2; i<n; i++){
        if(prime[i]){
            cnt++;
            for(int j=2*i; j<n; j=j+i){
                prime[j] = 0;
            }
        }
    }
    return cnt;
}
int main() {
int ans = count_no_of_prime(40);
cout<<ans<<endl;
return 0;
}