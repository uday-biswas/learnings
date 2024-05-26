#include <bits/stdc++.h>
using namespace std;
int main() {
while (1){
    string s;
    cin>>s;
    if(s.size()==0){
        break;
    }
    for(int i=0;i<s.size();i++){
        cout<<char(s[i] - 32);
    }
    cout<<endl;
}
return 0;
}