#include <bits/stdc++.h>
using namespace std;
string countAndSay(int n) {
        string ans= "11";
        int count=1;
        vector<char> ch;
        vector<int> arr;
        for(int i=0; i<n-2; i++){
            ch.clear();
            arr.clear();
            count =1;
            for(int j=0; j<ans.size()-1; j++){
                if(ans[j] == ans[j+1]) count++;
                else {
                    ch.push_back(ans[j]);
                    arr.push_back(count);
                    count=1;
                }
            }
            if(ans[ans.size()-1] == ans[ans.size()-2]){
                arr.push_back(count);
                ch.push_back(ans[ans.size()-1]);
            }
            else{
                arr.push_back(1);
                ch.push_back(ans[ans.size()-1]);
            }
            ans.clear();
            for(int k=0; k<ch.size(); k++){
                ans.push_back(char(arr[k] + '0'));
                ans.push_back(ch[k]);
            }
        }
        if(n==1) return "1";
        return ans;
    }
int main() {
int n=5;
string ans = countAndSay(n);
cout<<ans;
return 0;
}