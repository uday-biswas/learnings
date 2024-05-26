#include <bits/stdc++.h>
using namespace std;
int main() {
    string str = "APFGMRZXIFPSXKOQDRRQJBBZ";
int s=0, e=str.size()-1;
  char ch[e+2];
  while(s<=e){
      ch[s] = str[e];
      ch[e] = str[s];
      s++;
      e--;   
  }
  ch[str.size()] = '\0';
  string str1 = ch;
  cout<<ch;
return 0;
}