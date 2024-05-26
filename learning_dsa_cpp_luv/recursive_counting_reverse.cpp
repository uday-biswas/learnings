#include <bits/stdc++.h>
using namespace std;
void count_reverse(int n){
    //base condition
    if(n == 1){
        cout<<n<<endl;
        return;
    }
    //processing
    cout<<n<<" ";

    //recurrence relation
    count_reverse(n-1);
}
int main() {
int n;
cin>>n;
count_reverse(n);
return 0;
}