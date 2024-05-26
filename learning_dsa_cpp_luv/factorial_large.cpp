#include <bits/stdc++.h>
using namespace std;
vector<int> factorial(int N){
        // code here
        vector<int> ans;
        int prod =1;
        for(int i=N; i>0; i--){
            if(prod > INT_MAX/i) {
                ans.push_back(prod);
                prod = 1;
            }
            prod *= i;  
        }
        ans.push_back(prod);
        return ans;
    }
int main() {
int n=22;
vector<int> ans = factorial(n);
for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
}
return 0;
}