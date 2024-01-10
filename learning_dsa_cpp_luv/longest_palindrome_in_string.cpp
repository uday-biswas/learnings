#include <bits/stdc++.h>
using namespace std;
string longestPalin (string S) {
        // code here
        int s,e,p=1;
        string ans;
        for(int i=S.size(); i>=1; i--){
            for(int j=0; j<= S.size()-i; j++){
                ans =  S.substr(j,i);
                s=0; e=ans.size()-1; p=1;
                while(s<=e){
                    if(ans[s]!=ans[e]) {
                        p=0;
                        break;
                    }   
                    else{
                        s++;
                        e--;
                    }
                }
                if(p==1) return ans;
            }
        }
        return S.substr(0,1);
    }
int main() {
string str = "aaaabbaa";
string ans = longestPalin(str);
cout<<ans;
return 0;
}