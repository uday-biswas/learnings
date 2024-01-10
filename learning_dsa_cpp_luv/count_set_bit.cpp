#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin>>N;
    int count=0;
        while(N!=0){
            int b = N&1;
            if(b==1){ 
                count++;}

            N=N >> 1;
        }
        cout<<count;

return 0;
}