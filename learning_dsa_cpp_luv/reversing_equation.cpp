#include <bits/stdc++.h>
using namespace std;
int isNumber(char ch){
      if(ch >= '0' && ch <= '9'){
          return 1;
      }
      return 0;
  }
string reverseEqn (string s)
        {
            //code here.
            int i=0, j=s.size()-1;
            int k,l,m,n,len1,len2,br=0;
            while(i<j){
                if(isNumber(s[i])){
                    k = i;  l=i; i++;
                    while(isNumber(s[i]) && i<j){
                        l=i; i++;
                    }
                    if(i==j) break;
                }
                else{
                    k = i; l=i; i++;
                }
                if(isNumber(s[j])){
                    n = j;  m=j; j--;
                    while(isNumber(s[j]) && i<j){
                        if(i == j) br = 1;
                        m = j; j--;
                    }
                }
                else{
                    n = j; m=j; j--;
                }
                len1 = l - k +1;
                len2 = n - m +1;
                string sub1 = s.substr(k,len1);
                string sub2 = s.substr(m,len2);
                s.replace(m, len2, sub1);
                s.replace(k, len1, sub2);
                i = k + len2;
                j = n - len1;
            }
            return s;
        }
int main() {
string str = "5-67-7/47/35*10-96";
string ans = reverseEqn(str);
cout << ans << endl;
return 0;
}