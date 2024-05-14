#include <bits/stdc++.h>
using namespace std;
int main() {
int N = 1e7-1;
        vector<int> map(N,0);
        vector<int> ans,nums;
        int n;
        cin>>n;
        for(int i=0; i<(2*n + 2); i++){
            int x;
            cin>>x;
            nums.push_back(x);
        }
        for ( int i =0; i<nums.size(); i++){
            map[nums[i]]++;
        }
        for(int i=0; i<N; i++){
            if(map[i]==1) ans.push_back(i);
        }
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<5*1e6;
return 0;
}