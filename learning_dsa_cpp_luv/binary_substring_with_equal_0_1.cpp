#include <bits/stdc++.h>
using namespace std;
int find_binary_substring(string str){
    int i=1,top=-1,ans=0;
    vector<char> stack;
    stack.push_back(str[0]);
    while(i!=str.size()){
        stack.push_back(str[i]);
        if(stack.size()>1) {
        if(stack[stack.size()-1] != stack[stack.size()-2]){
            stack.pop_back();
            stack.pop_back();
            if(i!=str.size()-1){
            if(stack.empty()==1 || str[i+1]==stack[stack.size()-1]) {
                ans++;
                stack.clear();
            }}
        }
        }
        i++;
    }
    if(ans==0) return -1;
    return ans;
}
int main() {
string str = "0001000001000";
int ans = find_binary_substring(str);
cout<<ans;
return 0;
}