#include <bits/stdc++.h>
using namespace std;
void reverse(string &str, int i, int j){
    //base condition
    if(i>j) return;

    //processing
    swap(str[i],str[j]);

    //recurrence relation
    reverse(str, i+1, j-1);
}
int main() {
string str = "babbar";
reverse(str,0,str.size()-1);
cout<<str;
return 0;
}