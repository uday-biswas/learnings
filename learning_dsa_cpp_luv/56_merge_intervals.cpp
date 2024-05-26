#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int t=1, n = intervals.size();
        for(int i=0; i<n-1; i++){
            if(intervals[i][1] >= intervals[i+1][0]){      //{1,3},{2,6},{8,10},{15,18}
                if(t==1){
                ans.push_back({intervals[i][0], intervals[i+1][1]});
                t =0;
                }
                else if(t==0) {
                ans[ans.size()-1][1] = intervals[i+1][1]; }
            }
            else {
                   if(t==0) t=1;
                   else if(t==1) t=2;
                   if(t==2){
                       ans.push_back({intervals[i][0], intervals[i][1]});
                   }
            }
        }
        if(t) ans.push_back({intervals[n-1][0], intervals[n-1][1]});
        return ans;
    }
int main() {
vector<vector<int>> inter{{2,6},{1,3},{8,10},{15,18}};
vector<vector<int>> ans = merge(inter);
for(int i=0; i<ans.size(); i++){
    cout<<"{";
    for(int j=0; j<ans[i].size(); j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<"}, ";
}
return 0;
}