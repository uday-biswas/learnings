#include <bits/stdc++.h>
using namespace std;
int check_rotation(string s1, string s2){
    char temp;
    for(int i=0; i<s1.size(); i++){
          temp = s1[0];
          s1.replace(0,s1.size()-1, s1,1,s1.size()-1);
          s1[s1.size()-1] = temp;
          if(s1.compare(s2)==0) return 1;
    }
    return 0;
}
int main() {
string s1 ("ABCE");
string s2 ("CDAB");
int ans = check_rotation(s1, s2);
cout<<ans;
return 0;
}