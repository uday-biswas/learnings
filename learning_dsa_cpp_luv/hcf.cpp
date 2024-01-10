#include <bits/stdc++.h>
using namespace std;
int hcf(int a , int b){
    int min_ = min(a,b),hcf;
    for (int i=1; i<=min_; i++){
        if (a% i ==0 && b%i ==0){
            hcf = i;
        }
    }
    return hcf;
}
int main() {
cout<<hcf(7,12);
return 0;
}